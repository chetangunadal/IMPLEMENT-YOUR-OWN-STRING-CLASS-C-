#include<iostream>
#include<cstring>

using namespace std;

class String
{
    char *data = nullptr;

public:
    String() : data(new char[1])
    {
        data[0] = '\0';
    }

    String(const char *s)
    {
        if(s == nullptr)
            s = "";

        size_t n = strlen(s);
        data = new char[n + 1];

        for(int i = 0; i <= n; i++)
            data[i] = s[i];
    }

    String(const String &s)
    {
        data = new char[strlen(s.data) + 1];
        strcpy(data, s.data);
    }

    ~String()
    {
        if(data != nullptr)
        {
            delete []data;
            data = nullptr;
        }
    }

    void display()
    {
        cout << data << endl;
    }

    String& operator=(const String &s)
    {
        if(this == &s)
            return *this;

        char *temp = new char[strlen(s.data) + 1];
        strcpy(temp, s.data);

        delete []data;
        data = temp;

        return *this;
    }

    String operator+(const String &s) const
    {
        int n = strlen(data) + strlen(s.data) + 1;
        char *t = new char[n];

        strcpy(t, data);
        strcat(t, s.data);

        String result(t);

        delete []t;

        return result;
    }

    char& operator[](int index)
    {
        return data[index];
    }

    friend ostream& operator<<(ostream &out, const String &s);
    friend istream& operator>>(istream &in, String &s);

    friend bool operator>(String &, String &);
    friend bool operator<(String &, String &);
    friend bool operator>=(String &, String &);
    friend bool operator<=(String &, String &);
    friend bool operator==(String &, String &);
    friend bool operator!=(String &, String &);

    friend String& strcpy(String &, String &);
    friend String& strncpy(String &, String &, int);
    friend int strcmp(String &, String &);
    friend int strncmp(String &, String &, int);
    friend String& strcat(String &, String &);
    friend String& strncat(String &, String &, int);
    friend String& strrev(String &);
    friend String& strupr(String &);
    friend String& strlwr(String &);
    friend char* strchr(String &, char);
    friend char* strrchr(String &, char);
    friend char* strstr(String &, const char *);
    friend int strlen(String &);
};

ostream& operator<<(ostream &out, const String &s)
{
    out << s.data;
    return out;
}

istream& operator>>(istream &in, String &s)
{
    char temp[1000];
    in >> temp;

    {
        delete []s.data;
        s.data = new char[strlen(temp) + 1];
        strcpy(s.data, temp);
    }

    return in;
}

bool operator>(String &s, String &t)
{
    if(strcmp(s.data, t.data) > 0)
        return 1;
    else
        return 0;
}

bool operator<(String &s, String &t)
{
    if(strcmp(s.data, t.data) < 0)
        return 1;
    else
        return 0;
}

bool operator>=(String &s, String &t)
{
    if(strcmp(s.data, t.data) >= 0)
        return 1;
    else
        return 0;
}

bool operator<=(String &s, String &t)
{
    if(strcmp(s.data, t.data) <= 0)
        return 1;
    else
        return 0;
}

bool operator==(String &s, String &t)
{
    if(strcmp(s.data, t.data) == 0)
        return 1;
    else
        return 0;
}

bool operator!=(String &s, String &t)
{
    if(strcmp(s.data, t.data) != 0)
        return 1;
    else
        return 0;
}

String& strcpy(String &s, String &t)
{
    if(&s != &t)
        s = t;

    return s;
}

String& strncpy(String &s, String &t, int n)
{
    if(n < 0)
        return s;

    if(&s != &t)
    {
        char temp[n + 1];
        strncpy(temp, t.data, n);
        temp[n] = '\0';

        String a = temp;
        s = a;
    }

    return s;
}

int strcmp(String &s, String &t)
{
    int k = strcmp(s.data, t.data);
    return k;
}

int strncmp(String &s, String &t, int n)
{
    if(n < 0)
        return 0;

    return strncmp(s.data, t.data, n);
}

String& strcat(String &s, String &t)
{
    char temp[strlen(s.data) + strlen(t.data) + 1];

    strcpy(temp, s.data);
    strcat(temp, t.data);

    s = temp;

    return s;
}

String& strncat(String &s, String &t, int n)
{
    char temp[strlen(s.data) + n + 1];

    strcpy(temp, s.data);
    strncat(temp, t.data, n);

    s = temp;

    return s;
}

String& strrev(String &s)
{
    int i = 0, j = strlen(s.data) - 1;
    char ch;

    while(i < j)
    {
        ch = s.data[i];
        s.data[i] = s.data[j];
        s.data[j] = ch;

        i++, j--;
    }

    return s;
}

String& strupr(String &s)
{
    for(int i = 0; s.data[i]; i++)
        if(s.data[i] >= 'a' && s.data[i] <= 'z')
            s.data[i] ^= 1 << 5;

    return s;
}

String& strlwr(String &s)
{
    for(int i = 0; s.data[i]; i++)
        if(s.data[i] >= 'A' && s.data[i] <= 'Z')
            s.data[i] ^= 1 << 5;

    return s;
}

char* strchr(String &s, char ch)
{
    for(int i = 0;; i++)
    {
        if(s.data[i] == ch)
            return &s.data[i];

        if(s.data[i] == '\0')
            break;
    }

    return nullptr;
}

char* strrchr(String &s, char ch)
{
    for(int i = strlen(s.data); i >= 0; i--)
        if(s.data[i] == ch)
            return &s.data[i];

    return nullptr;
}

char* strstr(String &s, const char *t)
{
    return strstr(s.data, t);
}

int strlen(String &s)
{
    int i;

    for(i = 0; s.data[i]; i++);

    return i;
}

