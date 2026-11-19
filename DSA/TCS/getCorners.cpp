#include <bits/stdc++.h>
using namespace std;

struct Pt {
    double x, y;
};

double cross(const Pt& a, const Pt& b, const Pt& c) {
    
    return (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
}

Pt reflectPoint(const Pt& p, const Pt& a, const Pt& b) {
    
    double A = b.y - a.y;
    double B = a.x - b.x;
    double C = -(A*a.x + B*a.y);

    double d = (A*p.x + B*p.y + C);
    double denom = (A*A + B*B);

    Pt r;
    r.x = p.x - 2 * A * d / denom;
    r.y = p.y - 2 * B * d / denom;
    return r;
}

bool segmentIntersectLine(Pt p1, Pt p2, Pt a, Pt b, Pt& out) {
    
    double A1 = p2.y - p1.y;
    double B1 = p1.x - p2.x;
    double C1 = -(A1*p1.x + B1*p1.y);

    double A2 = b.y - a.y;
    double B2 = a.x - b.x;
    double C2 = -(A2*a.x + B2*a.y);

    double D = A1*B2 - A2*B1;
    if (fabs(D) < 1e-9) return false; 

    double x = (B1*C2 - B2*C1) / D;
    double y = (C1*A2 - C2*A1) / D;

    
    if (min(p1.x, p2.x) - 1e-9 <= x && x <= max(p1.x, p2.x) + 1e-9 &&
        min(p1.y, p2.y) - 1e-9 <= y && y <= max(p1.y, p2.y) + 1e-9) {
        out = {x, y};
        return true;
    }
    return false;
}

int main() {
    
    vector<Pt> poly(4);
    cout << "Enter 4 square vertices (x y):\n";
    for (int i = 0; i < 4; i++) cin >> poly[i].x >> poly[i].y;

    Pt A, B;
    cout << "Enter fold line endpoints (both must be square corners):\n";
    cin >> A.x >> A.y >> B.x >> B.y;

    vector<Pt> result;
    int n = poly.size();

    for (int i = 0; i < n; i++) {
        Pt p1 = poly[i];
        Pt p2 = poly[(i+1)%n];

        double side1 = cross(A, B, p1);
        double side2 = cross(A, B, p2);

        
        if (side1 >= 0) result.push_back(p1);

        
        if ((side1 < 0 && side2 > 0) || (side1 > 0 && side2 < 0)) {
            Pt inter;
            if (segmentIntersectLine(p1, p2, A, B, inter)) {
                result.push_back(inter);
            }
        }

        
        if (side2 < 0) {
            Pt rp = reflectPoint(p2, A, B);
            result.push_back(rp);
        }
    }

    
    auto eq = [](const Pt &a, const Pt &b) {
        return fabs(a.x-b.x) < 1e-6 && fabs(a.y-b.y) < 1e-6;
    };

    vector<Pt> finalPoly;
    for (auto &p : result) {
        bool found = false;
        for (auto &q : finalPoly)
            if (eq(p,q)) { found = true; break; }
        if (!found) finalPoly.push_back(p);
    }

    
    sort(finalPoly.begin(), finalPoly.end(), [](const Pt& a, const Pt& b){
        if (fabs(a.x - b.x) > 1e-9) return a.x < b.x;
        return a.y < b.y;
    });

    cout << "\nFinal folded polygon vertices:\n";
    for (auto &p : finalPoly) {
        cout << fixed << setprecision(6);
        cout << "(" << p.x << ", " << p.y << ")\n";
    }

    return 0;
}
