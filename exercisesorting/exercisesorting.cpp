//1. Algoritma dibutuhkan dalam menyelesaikan masalah karena dapat mempermudah dalam memecahkan suatu masalah, dengan adanya algoritma, kita akan  mengetahui kondisi awal dari suatu masalah, apa yang terjadi, dan bagaimana cara kita dalam memecahkan suatu masalah tersebut serta mengetahui hasilnya
//2. Dua struktur data yaitu static (contoh: array), dynamic (contoh: linked list)
//3. Faktor yang mempengaruhi efesiensi waktu: speed of the machine(kecepatan mesin/device), compiler(penyusun), operating system(sistem oprasi), progaming langugae(bahasa pemograman), size of the input(ukuran dari input), serta cara pengorganisasian data suatu program, dan algoritma yang digunakan
//4. Menurut saya, algritma QuickSort, karena lebih mudah untuk mengurutkan sebuah data dengan cara data diubah menjadi dua bagian hingga mudah untuk kita menyelesaikannya
//5. Yang termasuk Quadratic = Bubble Sort, Insertion Sort, Selection Sort, sedangkan yang termasuk Loglinear = Quick Sort, Merge Sort


#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& brili, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> left_brili(n1);
    vector<int> right_brili(n2);

    for (int i = 0; i < n1; i++)
        left_brili[i] = brili[left + i];
    for (int BT = 0; BT < n2; BT++)
        right_brili[BT] = brili[mid + 1 + BT];

    int i = 0;
    int BT = 0;
    int k = left;

    while (i < n1 && BT < n2) {
        if (left_brili[i] <= right_brili[BT]) {
            brili[k] = left_brili[i];
            i++;
        }
        else {
            brili[k] = right_brili[BT];
            BT++;
        }
        k++;
    }

    while (i < n1) {
        brili[k] = left_brili[i];
        i++;
        k++;
    }

    while (BT < n2) {
        brili[k] = right_brili[BT];
        BT++;
        k++;
    }
}

void merge_sort(vector<int>& brili, int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(brili, left, mid);
        merge_sort(brili, mid + 1, right);

        merge(brili, left, mid, right);
    }
}

void print_vector(vector<int>& brili)
{
    for (int i = 0; i < brili.size(); i++)
        cout << brili[i] << " ";
    cout << endl;
}

int main()
{
    vector<int> brili = { 43, 73, 54, 94, 98, 62, 6, 35, 11, 63, 56, 19, 9, 42, 67, 29, 87, 68, 85, 51, 22, 49, 95, 58, 39, 24, 61, 40, 20, 104, 25, 80, 86, 111, 83, 113, 88, 44, 3, 10, 78, 71, 46, 102, 79, 33, 27, 75, 64, 89, 30, 91, 101, 112, 70, 82, 100, 12, 52, 55, 69, 26, 7, 1, 76, 90, 60, 13, 34, 107, 18, 14, 57, 53, 48, 31, 66, 50, 96, 92, 8, 77, 108, 5, 23, 106, 99, 116, 97, 110, 45, 37, 115, 21, 84, 47, 72, 36, 81, 65, 41, 109, 59, 17, 28, 105, 4, 2, 38, 16, 74, 93, 32, 114 };
    int n = brili.size();

    cout << "Array Sebelum diurutkan: ";
    print_vector(brili);

    merge_sort(brili, 0, n - 1);

    cout << "Array Telah Terurutkan: ";
    print_vector(brili);

    return 0;
}