#include <cstdio>
#include <iostream>
#include <vector>

class Rekening {

protected:
    int mNoRekening;
    double mSaldo;
    
    Rekening (int noRekening) {
        mNoRekening = noRekening;
        mSaldo = 0.0;
    }

public:
    double getSaldo () {
        return mSaldo;
    }
};

class RekeningTabungan : public Rekening {

public:
    RekeningTabungan (int noRekening) : Rekening (noRekening) {}
    
    void menabung (double jumlah) {
        mSaldo += jumlah;
    }
    
    bool ambilTabungan (double jumlah) {
        if (mSaldo >= jumlah) {
            mSaldo = mSaldo - jumlah;
            return true;
        }
        else return false;
    }
};

class RekeningUtang : public Rekening {

public:
    RekeningUtang (int noRekening) : Rekening (noRekening) {}
    
    void pinjam (double jumlah) {
        mSaldo = mSaldo + jumlah;
    }
    
    void cicil (double jumlah) {
        mSaldo = mSaldo - jumlah;
    }
};

class Anggota {
    
    std::vector<Rekening> mRekening;

public:
    bool bukaRekeningTabungan () {
        RekeningTabungan tabunganBaru (mRekening.size ());
        mRekening.insert (mRekening.end (), tabunganBaru);
        return true;
    }
    
    bool bukaRekeningUtang () {
        RekeningUtang utangBaru (mRekening.size ());
        mRekening.insert(mRekening.end (), utangBaru);
        return true;
    }
    
    double cekSaldo (int noRekening) {
        if (noRekening < mRekening.size ()) {
            return mRekening[noRekening].getSaldo ();
        }
        else return -1;
    }
    
    bool menabung (int noRekening, double jumlah) {
        if (noRekening < mRekening.size()) {
            ((RekeningTabungan*) &mRekening[noRekening])->menabung (jumlah);
            return true;
        }
        else return false;
    }
    
    bool ambilTabungan (int noRekening, double jumlah) {
        if (noRekening < mRekening.size()) {
            return ((RekeningTabungan*) &mRekening[noRekening])->ambilTabungan (jumlah);
        }
        else return false;
        
    }
    
    bool pinjam (int noRekening, double jumlah) {
        if (noRekening < mRekening.size()) {
            ((RekeningUtang*) &mRekening[noRekening])->pinjam (jumlah);
            return true;
        }
        else return false;
    }
    
    bool cicil (int noRekening, double jumlah) {
        if (noRekening < mRekening.size()) {
            ((RekeningUtang*) &mRekening[noRekening])->cicil (jumlah);
            return true;
        }
        else return false;
    }
};

int main () {
    Anggota dio, ronald;
    dio.bukaRekeningTabungan ();
    ronald.bukaRekeningUtang ();
    
    printf ("Dio: %g\n", dio.cekSaldo (0));
    printf ("Ronald: %g\n", ronald.cekSaldo (0));
    printf ("\n");
    
    dio.menabung (0, 10000);
    ronald.pinjam (0, 10000);
    
    printf ("Dio: %g\n", dio.cekSaldo (0));
    printf ("Ronald: %g\n", ronald.cekSaldo (0));
    printf ("\n");
    
    dio.ambilTabungan (0, 2500);
    ronald.cicil (0, 7500);
    
    printf ("Dio: %g\n", dio.cekSaldo (0));
    printf ("Ronald: %g\n", ronald.cekSaldo (0));
    printf ("\n");
}