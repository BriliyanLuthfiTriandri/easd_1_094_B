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
    vector<int> brili = { 92, 67, 30, 49, 8, 13, 73, 39, 52, 71, 20, 29, 60, 76, 53, 91, 99, 61, 35, 44, 96, 51, 75, 78, 86, 9, 17, 81, 40, 12, 27, 36, 32, 55, 83, 22, 15, 97, 1, 68, 3, 33, 89, 7, 98, 25, 42, 65, 43, 87, 70, 64, 2, 6, 50, 48, 11, 45 };
    int n = brili.size();

    cout << "Array Sebelum diurutkan: ";
    print_vector(brili);

    merge_sort(brili, 0, n - 1);

    cout << "Array Telah Terurutkan: ";
    print_vector(brili);

    return 0;
}