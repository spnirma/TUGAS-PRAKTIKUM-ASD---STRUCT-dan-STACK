#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'twoStacks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER maxSum
 *  2. INTEGER_ARRAY a
 *  3. INTEGER_ARRAY b
*/

int twoStacks(int maxSum, int a_count, int* a, int b_count, int* b) {
    int count = 0; //Mendeklarasikan variabel lokal count dan menginisialisasinya dengan nilai 0. Variabel ini akan digunakan untuk menghitung jumlah elemen yang diambil dari kedua tumpukan
    int temporarySum = 0; //Mendeklarasikan variabel lokal temporarySum dan menginisialisasinya dengan nilai 0. Variabel ini akan digunakan untuk menyimpan jumlah sementara elemen yang diambil dari tumpukan
    int idx_a = 0, idx_b = 0; //Mendeklarasikan dan menginisialisasikan dua variabel lokal idx_a dan idx_b dengan nilai 0. Variabel ini digunakan sebagai indeks untuk mengakses elemen dari tumpukan a dan b

    // Loop untuk mengambil bilangan bulat dari tumpukan pertama (a) sebanyak mungkin
    while (idx_a < a_count && temporarySum + a[idx_a] <= maxSum) { //oop untuk mengambil elemen dari tumpukan pertama (a) sebanyak mungkin selama jumlah sementara elemen yang diambil tidak melebihi maxSum
        temporarySum += a[idx_a]; //Menambahkan nilai elemen yang diambil dari tumpukan pertama ke temporarySum
        idx_a = idx_a + 1; //Meningkatkan indeks idx_a untuk mengambil elemen berikutnya dari tumpukan pertama
        count = count + 1; //Menambahkan 1 ke jumlah total elemen yang telah diambil
    }

    // Simpan jumlah maksimum elemen yang diambil dari tumpukan pertama
    int maxElementCount = count;

    // Loop untuk mengambil bilangan bulat dari tumpukan kedua (b) dan memperbarui jumlah bilangan bulat yang diambil
    while (idx_b < b_count && idx_a >= 0) { //Mulai dari sini adalah loop untuk mengambil elemen dari tumpukan kedua (b) dan memeriksa apakah jumlah elemen yang diambil melebihi jumlah maksimum yang telah ditentukan sebelumnya
        temporarySum += b[idx_b]; //Menambahkan nilai elemen yang diambil dari tumpukan kedua ke temporarySum
        idx_b = idx_b + 1; //Meningkatkan indeks idx_b untuk mengambil elemen berikutnya dari tumpukan kedua
        count = count + 1; //Menambahkan 1 ke jumlah total elemen yang telah diambil

        // Memastikan total jumlah bilangan bulat yang diambil tidak melebihi maxSum
        while (temporarySum > maxSum && idx_a > 0) { //Memulai loop untuk memastikan total jumlah elemen yang diambil tidak melebihi maxSum
            idx_a = idx_a - 1; //Mengurangi indeks idx_a untuk mengurangi jumlah elemen dari tumpukan pertama
            temporarySum -= a[idx_a]; //Mengurangi nilai elemen yang diambil dari temporarySum
            count = count - 1; //Mengurangi 1 dari jumlah total elemen yang telah diambil
        }

        // Memeriksa apakah jumlah elemen saat ini melebihi jumlah elemen maksimum sebelumnya
        if (temporarySum <= maxSum && count > maxElementCount) { //Memeriksa apakah jumlah elemen yang diambil sekarang tidak melebihi maxSum dan jika iya, apakah jumlah elemen saat ini lebih besar dari jumlah elemen maksimum yang telah disimpan sebelumnya
            maxElementCount = count; //ika ya, maka jumlah elemen saat ini menjadi jumlah maksimum yang baru
        }
    }

    return maxElementCount; //Mengembalikan jumlah maksimum elemen yang diambil dari kedua tumpukan
}

int main() {
    int g; //Mendeklarasikan variabel g untuk menyimpan jumlah permainan
    scanf("%d", &g); //Meminta input dari pengguna untuk jumlah permainan

    for (int g_itr = 0; g_itr < g; g_itr++) { //Loop untuk setiap permainan.
        int n, m, maxSum; //Mendeklarasikan variabel untuk menyimpan jumlah elemen dalam tumpukan a dan b, serta jumlah maksimum yang tidak boleh dilewati
        scanf("%d", &n); //Meminta input untuk jumlah elemen dalam tumpukan pertama a
        scanf("%d",&m); //Meminta input untuk jumlah elemen dalam tumpukan kedua b
        scanf("%d",&maxSum); //Meminta input untuk jumlah maksimum yang tidak boleh dilewati

        int* a = malloc(n * sizeof(int)); //Mengalokasikan memori untuk tumpukan a
        for (int i = 0; i < n; i++) { //Loop untuk mengisi elemen tumpukan a
        scanf("%d", &a[i]);   //Meminta input untuk setiap elemen tumpukan a
        }

        int* b = malloc(m * sizeof(int)); //Mengalokasikan memori untuk tumpukan b
        for (int i = 0; i < m; i++) { //Loop untuk mengisi elemen tumpukan b
            scanf("%d", &b[i]); //Meminta input untuk setiap elemen tumpukan b
        }

        int result = twoStacks(maxSum, n, a, m, b); //Memanggil fungsi twoStacks untuk menghitung jumlah maksimum elemen yang dapat diambil
        printf("%d\n", result); //Menampilkan hasil jumlah maksimum elemen yang dapat diambil

        free(a); //Membebaskan memori yang dialokasikan untuk tumpukan a
        free(b); //Membebaskan memori yang dialokasikan untuk tumpukan b
    }

    return 0; //Mengembalikan nilai 0 untuk menunjukkan bahwa program berakhir 
}



char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
