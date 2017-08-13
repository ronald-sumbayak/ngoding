#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef struct s_hotel {
    int bed, capacity, room, price;
    string name;
    
    bool operator < (const struct s_hotel &s) const {
        if (price == s.price)
            return bed > s.bed;
        return price < s.price;
    }
} Hotel;

int main (int argc, char **argv) {
    int tc, n, m;
    cin >> tc;
    
    for (int t = 1; t <= tc; t++) {
        cin >> n >> m;
        vector<Hotel> a, b, c;
        
        for (int i = 0; i < n; i++) {
            Hotel h;
            cin >> h.bed >> h.capacity >> h.room >> h.price >> h.name;
            
            if (20 <= h.bed && h.bed <= 35) a.push_back (h);
            else if (36 <= h.bed && h.bed <= 48) b.push_back (h);
            else if (49 <= h.bed && h.bed <= 62) c.push_back (h);
        }
        
        vector<Hotel> *p;
        cout << "Case #" << t << ":" << "\n";
        sort (a.begin (), a.end ());
        sort (b.begin (), b.end ());
        sort (c.begin (), c.end ());
        
        for (int i = 0; i < m; i++) {
            int size, maxroom;
            char bed;
            cin >> bed >> size >> maxroom;
    
            if (bed == 'A') p = &a;
            else if (bed == 'B') p = &b;
            else if (bed == 'C') p = &c;
            else p = new vector<Hotel> ();
            
            string suggestion = "no-hotel";
            int total = 0;
            for (int j = 0; j < p->size (); j++) {
                Hotel h = p->operator[] ((unsigned int) j);
                int required = (int) (ceil ((float) size / maxroom));
                // cout << ':' << ends << h.bed << ends << h.room << ends << h.capacity << ends << h.capacity << ends << h.price << ends << h.name << endl;
    
                if (h.capacity >= maxroom && h.room >= required) {
                    total = required * h.price;
                    suggestion = h.name;
                    break;
                }
            }
            
            if (suggestion != "no-hotel") cout << total << " ";
            cout << suggestion << "\n";
        }
    }
}