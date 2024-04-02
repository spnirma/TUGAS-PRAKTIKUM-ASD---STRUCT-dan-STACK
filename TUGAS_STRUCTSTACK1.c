#include <stdio.h> // Mengimpor library standar input-output
#include <stdlib.h> // Mengimpor library standar untuk fungsi-fungsi umum

struct Node { // Deklarasi struktur Node
    char* alphabet; // Mendefinisikan pointer ke karakter untuk menyimpan huruf
    struct Node* link; // Mendefinisikan pointer ke Node berikutnya
};

int main() { // Fungsi utama program
    // Deklarasi node-node
    struct Node l1, l2, l3, l4, l5, l6, l7, l8, l9; // Mendeklarasikan node-node
    // Deklarasi pointer ke Node
    struct Node *l3ptr;

    // Inisialisasi node-node dengan menggunakan potongan kode
    l1.link = NULL; //Mengatur link dari l1 ke NULL
    l1.alphabet = "F"; //Mengatur nilai alphabet dari l1 menjadi "F"
    l2.link = NULL; //Mengatur link dari l2 ke NULL
    l2.alphabet = "M"; //Mengatur nilai alphabet dari l2 menjadi "M"
    l3.link = NULL; //Mengatur link dari l3 ke NULL
    l3.alphabet = "A"; //Mengatur nilai alphabet dari l3 menjadi "A"
    l4.link = NULL; //Mengatur link dari l4 ke NULL
    l4.alphabet = "I"; //Mengatur nilai alphabet dari l4 menjadi "I"
    l5.link = NULL; //Mengatur link dari l5 ke NULL
    l5.alphabet = "K"; //Mengatur nilai alphabet dari l5 menjadi "K"
    l6.link = NULL; //Mengatur link dari l6 ke NULL
    l6.alphabet = "T"; //Mengatur nilai alphabet dari l6 menjadi "T"
    l7.link = NULL; //Mengatur link dari l7 ke NULL
    l7.alphabet = "N"; //Mengatur nilai alphabet dari l7 menjadi "N"
    l8.link = NULL; //Mengatur link dari l8 ke NULL
    l8.alphabet = "O"; //Mengatur nilai alphabet dari l8 menjadi "O"
    l9.link = NULL; //Mengatur link dari l9 ke NULL
    l9.alphabet = "R"; //Mengatur nilai alphabet dari l9 menjadi "R"

    // Mengatur koneksi antar node sesuai dengan urutan yang diinginkan
    l7.link = &l1; // N -> F
    l1.link = &l8; // F -> O
    l8.link = &l2; // O -> M
    l2.link = &l5; // M -> K
    l5.link = &l3; // K -> A
    l3.link = &l6; // A -> T
    l6.link = &l9; // T -> R
    l9.link = &l4; // R -> I
    l4.link = &l7; // I -> N

    // Starting point
    l3ptr = &l3;

    // Menampilkan huruf sesuai dengan jalur koneksi node
    printf("%s", l3.link->link->link->alphabet); // Menampilkan huruf I dengan jalur koneksi node l3.link ke l4.link
    
    printf("%s", l3.link->link->link->link->alphabet); // Menampilkan huruf N dengan jalur koneksi node l3.link ke l7.link
    
    printf("%s", l3.link->link->link->link->link->alphabet); // Menampilkan huruf F dengan jalur koneksi node l3.link ke l1.link
    
    printf("%s", l3.link->link->link->link->link->link->alphabet); // Menampilkan huruf O dengan jalur koneksi node l3.link ke l8.link
    
    printf("%s", l3.link->link->alphabet); // Menampilkan huruf R dengan jalur koneksi node l3.link ke l9.link
    
    printf("%s", l3.link->link->link->link->link->link->link->alphabet); // Menampilkan huruf M dengan jalur koneksi node l3.link ke l2.link
    
    printf("%s", l3.alphabet); // Menampilkan huruf A dari jalur koneksi node l3.link 
    
    printf("%s", l3.link->alphabet); // Menampilkan huruf T dengan jalur koneksi node l3.link ke l6.link
    
    printf("%s", l3.link->link->link->alphabet); // Menampilkan huruf I dengan jalur koneksi node l3.link ke l4.link
    
    printf("%s", l3.link->link->link->link->link->link->link->link->alphabet); // Menampilkan huruf K dengan jalur koneksi node l3.link ke l5.link
    
    printf("%s", l3.alphabet); // Menampilkan huruf A dari jalur koneksi node l3.link 

    return 0; //Mengakhiri fungsi main() dengan mengembalikan nilai 0, menandakan bahwa program berakhir tanpa kesalahan
}
