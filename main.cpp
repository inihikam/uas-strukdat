#include "pustaka.h"

int main()
{
    int dataList = 20;
    string listLagu[dataList] = {"Scared",
                           "All the kids are depressed",
                           "Daylight",
                           "18",
                           "One Time",
                           "Ghost",
                           "Circles",
                           "Sunflower"};

    int durasiLagu[dataList] = {3, 4, 4, 4, 3, 2, 3, 2};
    string listGenre[dataList] = {"POP", "POP", "POP", "POP",
                            "POP", "POP", "POP", "POP"};
    int choose;
    for (i = 0; i < 8; i++)
    {
        insertEnd(listLagu[i], durasiLagu[i], listGenre[i]);
    }

    do
    {
        system("cls");
        cout << endl;
        cout << " =============================" << endl;
        cout << " =    PROGRAM LIST MUSIC     =" << endl;
        cout << " =============================" << endl;
        cout << " = 1. Insert Music           =" << endl;
        cout << " = 2. Delete Music           =" << endl;
        cout << " = 3. Show Music             =" << endl;
        cout << " = 4. Exit Program           =" << endl;
        cout << " =============================" << endl;
        cout << " Pilihan : ";
        cin >> choose;

        switch (choose)
        {
        case 1:
            system("cls");
            {
                if (i == dataList)
                {
                    cout << "Penyimpanan lagu penuh!\n";
                }
                else
                {
                    cout << "Masukkan nama lagu   : "; 
                    cin.ignore();
                    getline(cin, listLagu[i]);
                    cout << "Masukkan durasi lagu : "; 
                    cin >> durasiLagu[i];
                    cout << "Masukkan genre lagu  : "; 
                    cin.ignore();
                    getline(cin, listGenre[i]);
                    cin >> listGenre[i];
                    insertEnd(listLagu[i], durasiLagu[i], listGenre[i]);
                    i++;
                }

                getch();
                break;
            }
        case 2:
            system("cls");
            {
                if (head == NULL)
                {
                    cout << "Maaf data masih kosong!\n";
                } else {
                    deleteSong();
                }
                getch();
                break;
            }
        case 3:
            system("cls");
            {
                if (head == NULL){
                    cout << "Maaf data lagu kosong!";
                } else {
                    showLagu();
                }
                
                getch();
                break;
            }
        case 4:
            system("cls");
            {
                return 0;
                break;
            }
        default:
            system("cls");
            {
                cout << "Maaf pilihan tidak ada!\n";
                getch();
                break;
            }
        }
    } while (choose != 4);

    cin.get();
    return 0;
}