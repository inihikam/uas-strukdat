#include "pustaka.h"

int main(){

    string listLagu[10] = {"Scared",
                           "All the kids are depressed",
                           "Daylight",
                           "18",
                           "One Time",
                           "Ghost",
                           "Circles",
                           "Sunflower"};

    int durasiLagu[10] = {3, 4, 4, 4, 3, 2, 3, 2};
    string listGenre[10] = {"POP", "POP", "POP", "POP", 
                            "POP", "POP", "POP", "POP"};

    int choose;
    do
    {
        cout << endl;
        cout << " =============================" << endl;
        cout << " =     PROGRAM LIST MUSIC    =" << endl;
        cout << " =============================" << endl;
        cout << " = 1. Insert Music           =" << endl;
        cout << " = 2. Show Music             =" << endl;
        cout << " = 3. Exit Program           =" << endl;
        cout << " =============================" << endl;
        cout << " Pilihan : ";
        cin >> choose;

        switch (choose){
            case 1 : system("cls");{
                cout << "Masukkan nama game : ";
                cin.ignore();
                getline(cin, namaGame);
                cout << "Masukkan tahun rilis game : ";
                cin >> tahun;
                insertData(namaGame, tahun);
                getch();
                break;
            }
            case 2 : system("cls");{
                if (isEmpty()){
                    cout << "Maaf list kosong!\n";
                } else {
                    delData();
                }
                
                getch();
                break;
            }
            case 3 : system("cls");{
                return 0;
                break;
            }
            default : system("cls");{
                cout << "Maaf pilihan tidak ada!\n";
                getch();
                break;
            }
        }
    } while (choose != 3);
    

    cin.get();
    return 0;
}