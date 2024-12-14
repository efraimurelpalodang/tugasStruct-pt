#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // Untuk std::setw

using namespace std;

// mendeklarasikan struct
struct mahasiswa
{
    string npm;
    string namaLengkap;
    string prodi;
    string ttl;
    int umur;
    double nilai;
    string ket;
};

int main() {
  // membuat vector dari struct mahasiswa dengan nama datamhs
  vector<mahasiswa> datamhs;
  string ulang, npm, nama, prodi, ttl, ket;
  double nilai;
  int umur;

  do {
      cout << "\nInput Data Mahasiswa: " << endl;
      cout << "=======================" << endl;
      cout << "NPM : "; cin >> npm;
      cin.ignore(); // Mengabaikan newline yang tersisa di buffer
      cout << "Nama Lengkap : "; getline(cin, nama); // Menggunakan getline untuk nama
      cout << "Prodi : "; getline(cin, prodi); // Menggunakan getline untuk prodi
      cout << "TTL (Format: tgl-bln-tahun): "; getline(cin, ttl); // Menggunakan getline untuk TTL
      cout << "Nilai : "; cin >> nilai;

      // mengambil tahun lahir
      string tahun = ttl.substr(6);
      umur = 2024 - atoi(tahun.c_str());

      // keterangan menggunakan operator ternary jika nilai >= 60 maka akan lulus
      ket = (nilai >= 60) ? "LULUS" : "TIDAK LULUS";
      

      // mengisi nilai vector dari data yang sudah user inputkan
      datamhs.push_back({npm, nama, prodi, ttl, umur, nilai, ket});

      cout << "Apakah Anda ingin menambahkan data lagi? (ya/tidak): ";
      cin >> ulang;

  } while (ulang == "ya");

  // menampilkan data vector dalam format tabel
  cout << "\nData Mahasiswa Yang Sudah Ditambahkan!!" << endl << endl; 
  cout << string(100, '-') << endl; // Garis pemisah
  cout << left << setw(15) << "NPM" 
        << setw(23) << "Nama Lengkap" 
        << setw(20) << "Prodi" 
        << setw(15) << "TTL" 
        << setw(7) << "Umur" 
        << setw(10) << "Nilai"
        << setw(10) << "Keterangan" << endl;
  cout << string(100, '-') << endl; // Garis pemisah

  for (const auto& mhs : datamhs) {
    cout << setw(15) << mhs.npm 
          << setw(23) << mhs.namaLengkap 
          << setw(20) << mhs.prodi 
          << setw(15) << mhs.ttl 
          << setw(7) << mhs.umur 
          << setw(10) << mhs.nilai
          << setw(10) << mhs.ket << endl;
  }
  cout << string(100, '-') << endl; // Garis pemisah

  return 0;
}