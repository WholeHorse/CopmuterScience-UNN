#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
using namespace std;



class String{
    char * buffer = NULL;
    int size = 0;

    String(int _size) : buffer(new char [_size]), size(_size - 1) {}

    public:
    String() = default;

    String(const String & str) : 
    buffer(new char[str.size + 1]), size(str.size){
        strcpy(buffer, str.buffer);
    }

    String(const char * p) : 
    buffer(new char[strlen(p)+1]), size(strlen(p)) { // +1 для /0
        strcpy(buffer, p);
    }

    ~String() {
        delete [] buffer;
    }

    char & operator[](int i)
    {
        if(i < 0 || i >= size) exit(1);
        else return buffer[i];
    }

    const char & operator[](int i) const
    {
        if(i < 0 || i >= size) exit(1);
        else return buffer[i];
    }

    String & operator =(const String & str)
    {
        if(this != &str){
            if(size < str.size){
                delete [] buffer;
                buffer = new char[str.size + 1];
            }
            strcpy(buffer, str.buffer);
            size = str.size;
        }
        return *this;
    }

    bool operator==(const String & str) const{
        return strcmp(buffer, str.buffer) == 0;
    }

    bool operator!=(const String & str) const{
        return strcmp(buffer, str.buffer) != 0;
    }

    bool operator>(const String & str) const{
        return strcmp(buffer, str.buffer) > 0;
    }

    bool operator<(const String & str) const{
        return strcmp(buffer, str.buffer) < 0;
    }

    String operator+(const String & str) const{
        String sum(str.size + 1 + size);
        strcpy(sum.buffer, buffer);
        strcat(sum.buffer, str.buffer);
        return sum;
    }

    String& operator+=(const String & str){
        int new_size = size + str.size;
        char* new_buffer = new char[size + str.size + 1];
        strcpy(new_buffer, buffer);
        strcat(new_buffer, str.buffer);
        delete[] buffer;
        buffer = new_buffer;
        size = new_size;
        return *this;
    }

    friend istream & operator >>(istream& in, String& str) {
        delete [] str.buffer;
        char ch;
        int chunk_size = 10;
        int i = 0;
        int buffer_size;
        char* buffer = new char[chunk_size];
        while (in.get(ch) && ch != '\n') {
            if (i == buffer_size - 1) {
                buffer_size += chunk_size;
                char* new_buffer = new char[buffer_size];
                strncpy(new_buffer, buffer, i);
                delete[] buffer;
                buffer = new_buffer;
                }
            buffer[i++] = ch;
        }
        buffer[i] = '\0';
        str.buffer = buffer;
        str.size = i;
        return in;
    }

    friend ostream & operator <<(ostream& out, const String& str){
        if (str.size == 0){
            cout << "error: Str empty";
            return out;
        }
        else{
            cout << "string = " << str.buffer << " size = " << str.size;
            return out;
        }
        
    }
};

int main()
{
    //const String str1 = "ABCDEF";
    String str1 = "ABCDEF";
    String str2("ABC1231321CEF");
    String str3 = "BOBS";
    /*String str3 = str2;

    str3[1] = 'A';
    cout << str1[2] << endl;
    cout << str2 << endl;
    cout << str3 << endl;*/
    /*
    str2 = str1;
    str1[0] = 'X';
    cout<<str2;
    */
    str1 += str2;
    cout << str1 << endl; 
    cin >> str3;
    cout << str3;
    return 0;
}