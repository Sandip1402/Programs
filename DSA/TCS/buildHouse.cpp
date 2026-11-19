#include <bits/stdc++.h>
using namespace std;

vector<string> build_house(int length, int height, char dir) {
    //
    int roofH = (length + 1) / 2;
    
    int leftPad = roofH;
    int rightPad = roofH;
    int width = leftPad + length + rightPad;
    int totalRows = roofH + height + 1; 

    
    vector<string> grid(totalRows, string(width, ' '));

    int baseRow = totalRows - 1;
    int baseLeft = leftPad;
    int baseRight = leftPad + length - 1;

    
    for (int x = baseLeft; x <= baseRight; ++x) grid[baseRow][x] = '#';

    
    for (int r = 1; r <= height; ++r) {
        int row = baseRow - r;
        if (row >= 0) {
            grid[row][baseLeft] = '@';
            grid[row][baseRight] = '&';
        }
    }

    
    
    
    for (int i = 0; i < roofH; ++i) {
        int leftCol = leftPad - 1 - i;
        int rightCol = baseRight + 1 + i;
        int row = baseRow - height - 1 - i;
        if (row >= 0 && leftCol >= 0 && rightCol < width) {
            grid[row][leftCol] = '/';
            grid[row][rightCol] = '\\'; 
        }
    }

    
    
    auto flip_vertical = [&](vector<string> &g) {
        reverse(g.begin(), g.end());
    };
    auto mirror_horizontal = [&](vector<string> &g) {
        for (auto &row : g) {
            reverse(row.begin(), row.end());
            
            for (char &c : row) {
                if (c == '/') c = '\\';
                else if (c == '\\') c = '/';
                else if (c == '@') c = '&';
                else if (c == '&') c = '@';
            }
        }
    };

    
    vector<string> out = grid;
    if (dir == 'H' || dir == 'U') {
        
    } else if (dir == 'D') {
        flip_vertical(out);
    } else if (dir == 'L') {
        mirror_horizontal(out);
    } else if (dir == 'R') {
        mirror_horizontal(out);
    } else {
        
    }

    
    
    return out;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    
    
    vector<string> specs;
    
    string first;
    if (!(cin >> first)) return 0;

    
    auto is_integer = [&](const string &s)->bool{
        if (s.empty()) return false;
        for (char c : s) if (!isdigit(c) && c != '-' && c != '+') return false;
        return true;
    };

    if (is_integer(first)) {
        int n = stoi(first);
        for (int i = 0; i < n; ++i) {
            string tok;
            if (!(cin >> tok)) {
                
                break;
            }
            specs.push_back(tok);
        }
        
        string t;
        while (cin >> t) specs.push_back(t);
    } else {
        
        specs.push_back(first);
        string t;
        while (cin >> t) specs.push_back(t);
    }

    
    struct HouseSpec { int length; int height; char dir; };
    vector<HouseSpec> houses;
    for (auto &s : specs) {
        
        
        size_t posx = s.find('x');
        if (posx == string::npos || s.size() < 3) continue;
        char dir = s.back();
        string left = s.substr(0, posx);
        string mid = s.substr(posx + 1, s.size() - posx - 2); 
        int len = stoi(left);
        int h = stoi(mid);
        houses.push_back({len, h, dir});
    }

    if (houses.empty()) {
        
        return 0;
    }

    
    vector<vector<string>> blocks;
    int maxRows = 0;
    for (auto &hs : houses) {
        auto blk = build_house(hs.length, hs.height, hs.dir);
        maxRows = max(maxRows, (int)blk.size());
        blocks.push_back(move(blk));
    }

    
    for (auto &blk : blocks) {
        int cur = blk.size();
        if (cur < maxRows) {
            int toPad = maxRows - cur;
            int width = blk.empty() ? 0 : blk[0].size();
            vector<string> pad(toPad, string(width, ' '));
            
            vector<string> newblk;
            newblk.reserve(maxRows);
            for (auto &r : pad) newblk.push_back(r);
            for (auto &r : blk) newblk.push_back(r);
            blk.swap(newblk);
        }
    }

    
    for (int r = 0; r < maxRows; ++r) {
        string out;
        for (size_t i = 0; i < blocks.size(); ++i) {
            out += blocks[i][r];
        }
        
        int lastNonSpace = (int)out.size() - 1;
        while (lastNonSpace >= 0 && out[lastNonSpace] == ' ') --lastNonSpace;
        if (lastNonSpace < 0) cout << "\n";
        else {
            cout << out.substr(0, lastNonSpace + 1) << "\n";
        }
    }

    return 0;
}
