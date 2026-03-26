#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <windows.h>  // For sleep() on Unix/Linux; use <windows.h> and Sleep() on Windows
#include <unistd.h>

using namespace std;

vector<vector<pair<int,int>>> pegs(3);  // Pegs: 0=A (source), 1=B (aux), 2=C (dest)

void clearScreen() {
    cout << "\033[2J\033[1;1H";  // ANSI escape for clear screen and home cursor
}

void printState(int step) {
    clearScreen();
    cout << "Tower of Hanoi - Step " << step << " (Disks: " << pegs[0].size() + pegs[1].size() + pegs[2].size() << " total)" << endl << endl;
    
    // Draw top of pegs
    cout << "  A     B     C  " << endl;

    
    // Find max disk size for height
    int maxDisk = 0;
    for (auto& peg : pegs) for (int d : peg) maxDisk = max(maxDisk, d);
    
    // Draw disks from smallest to largest height
    for (int h = 1; h <= maxDisk; ++h) {
        for (int p = 0; p < 3; ++p) {
            bool hasDisk = false;
            for (int d : pegs[p]) {
                if (d == h) {
                    int width = 2 * h - 1;  // Larger disks wider
                    cout << left << setw(3) << "" << setw(width) << setfill('=') << "=" << setfill(' ') << "  ";
                    hasDisk = true;
                    break;
                }
            }
            if (!hasDisk) {
                cout << "|     ";
            }
        }
        cout << endl;
    }
    
    // Draw peg bases
    cout << " -----  -----  ----- " << endl << endl;
    cout << "Press Enter to continue..." << endl;
    // cin.get();  // Pause for user (remove for auto animation)
    usleep(500000);  // Uncomment for 0.5s auto delay instead of pause
}

void tower(int n, int from, int to, int aux, int step) {
    if (n == 0) return;
    
    tower(n - 1, from, aux, to, step);
    pegs[to].insert(pegs[to].begin(), n);  // Move disk n to 'to' peg (insert at front/top)
    printState(step);
    
    tower(n - 1, aux, to, from, step + 1);
}

int main() {
    int n;
    cout << "Enter number of disks (3-5 recommended): ";
    cin >> n;
    cin.ignore();  // Clear newline
    
    // Initialize source peg A with disks n down to 1 (largest at bottom)
    for (int i = n; i >= 1; --i) {
        pegs[0][i].first = n-i;
        pegs[0][i].second = i;
    }
    
    printState(0);  // Initial state
    tower(n, 0, 2, 1, 1);
    
    cout << "\nSolution complete in " << (1 << n) - 1 << " moves!" << endl;
    return 0;
}
