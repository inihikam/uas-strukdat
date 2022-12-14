#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>

using namespace std;

struct lagu
{
    string judul;
    int durasi;
    string genre;
    lagu *next;
    lagu *prev;
};

lagu *head = NULL;
lagu *tail = NULL;

int i = 0;

void insertEnd(string a, int b, string c)
{
    lagu *baru;
    lagu *bantu;
    baru = new lagu;
    baru->judul = a;
    baru->durasi = b;
    baru->genre = c;
    baru->next = NULL;
    baru->prev = NULL;

    if (head == NULL)
    {
        head = baru;
        tail = baru;
        tail->next = head;
        head->prev = tail;
        cout << "Data berhasil masuk!\n";
    }
    else
    {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
        tail->next = head;
        head->prev = tail;
        cout << "Data berhasil masuk!\n";
    }
}

void deleteSong()
{
    lagu *bantu;
    lagu *hapus;
    string searchGenre;
    bool found = false;
    bantu = head;
    cout << "Masukkan genre musik yang ingin dihapus : ";
    cin.ignore();
    getline(cin, searchGenre);
    do
    {
        // MENGHAPUS JIKA DATA HANYA ADA 1
        if (searchGenre == bantu->genre && head == tail)
        {
            hapus = head;
            head = NULL;
            tail = NULL;
            found = true;
            delete hapus;
            i--;
            break;
        }

        // MENGHAPUS DATA JIKA BERADA DI DEPAN
        if (searchGenre == head->genre)
        {
            hapus = head;
            head = head->next;
            tail->next = head;
            head->prev = tail;
            found = true;
            delete hapus;
            bantu = bantu->next;
            i--;
            continue;
        }

        // MENGHAPUS JIKA DATA LEBIH DARI 1 DAN DI TENGAH
        if (searchGenre == bantu->genre && searchGenre != head->genre)
        {
            hapus = bantu;
            bantu->prev->next = bantu->next;
            bantu->next->prev = bantu->prev;
            found = true;
            delete hapus;
            bantu = bantu->next;
            i--;
            continue;
        }

        // MENGHAPUS DATA JIKA BERADA DI BELAKANG
        if (searchGenre == tail->genre)
        {
            hapus = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            found = true;
            delete hapus;
            bantu = bantu->next;
            i--;
            continue;
        }
    } while (bantu != NULL);

    if (found == false)
    {
        cout << "Lagu tidak ditemukan!\n";
    }
    else
    {
        cout << "Genre " << searchGenre << " berhasil dihapus!\n";
    }
}

void showLagu()
{
    lagu *list;
    list = head;
    int i = 1;
    do
    {
        cout << i << ". " << list->judul << " | " << list->durasi
             << " | " << list->genre << "\n";
        i++;
        list = list->next;
    } while (list != head);
}