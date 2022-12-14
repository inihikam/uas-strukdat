#include <iostream>

using namespace std;

struct lagu{
    string judul;
    int durasi;
    string genre;
    lagu *next;
    lagu *prev;
};

lagu *head = NULL;
lagu *tail = NULL;

void insertEnd(string a, int b, string c){
    lagu *baru;
    lagu *bantu;
    baru = new lagu;
    baru->judul = a;
    baru->durasi = b;
    baru->genre = c;
    baru->next = NULL;
    baru->prev = NULL;

    if (head == NULL){
        baru = head;
        baru = tail;
        tail->next = head;
        head->prev = tail;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
        tail->next = head;
        head->prev = tail;
    }
}

void showLagu(){
    lagu *list;
    list = head;
    int i = 1;
    do
    {
        cout << i << ". " << list->judul << " | " << list->durasi
        << " | " << list->genre << "\n";
        list = list->next;
    } while (list != head);
    
}