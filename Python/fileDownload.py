import os
import requests
import time
import pandas as pd

# --- SETTINGS ---
excel_file = "Interview Preparation Bootcamp_ CS Core.xlsx"  # change to your Excel file name
link_column = "Video Link"       # change to the column name that has URLs
name_column = "Chapter Name"
output_folder = "CS Core - Interview Preparation"


# Create output folder if not exists
os.makedirs(output_folder, exist_ok=True)

# Read Excel file
df = pd.read_excel(excel_file)

for i, row in df.iterrows():
    try:
        url = str(row[link_column]).strip()
        name_from_excel = str(row[name_column]).strip()

        if not url.startswith("http"):
            print(f"Skipping row {i} (invalid URL): {url}")
            continue

        # Ensure filename ends with .webm
        if not name_from_excel.lower().endswith(".webm"):
            name_from_excel += ".webm"

        file_name = os.path.join(output_folder, name_from_excel)
        temp_file = file_name + ".part"

        # Resume support: check if partial file exists
        resume_header = {}
        downloaded_bytes = 0
        if os.path.exists(temp_file):
            downloaded_bytes = os.path.getsize(temp_file)
            resume_header = {"Range": f"bytes={downloaded_bytes}-"}
            print(f"Resuming {name_from_excel} from {downloaded_bytes} bytes...")

        # Retry mechanism
        for attempt in range(3):
            try:
                response = requests.get(
                    url, headers=resume_header, stream=True, timeout=(10, 30)
                )
                if response.status_code in (200, 206):  # 206 = partial content
                    break
                else:
                    raise Exception(f"Bad status code: {response.status_code}")
            except Exception as e:
                print(f"Attempt {attempt+1} failed for {name_from_excel}: {e}")
                if attempt == 2:  # last attempt
                    raise
                time.sleep(5)

        mode = "ab" if downloaded_bytes > 0 else "wb"  # append if resuming
        with open(temp_file, mode) as f:
            for chunk in response.iter_content(chunk_size=65536):
                if chunk:
                    f.write(chunk)

        # Rename after success
        os.rename(temp_file, file_name)
        print(f"✅ Downloaded {file_name}")

    except Exception as e:
        print(f"❌ Failed to download row {i}: {e}")

print("🎉 All downloads finished (with resume + custom filenames)!")
