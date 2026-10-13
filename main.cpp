#include"header.h"
int main()
{
    int ch;
    char *p;

    String s1("chetan");
    String s2("gunadal");
    String s3("hello");
    String s4("world");

    while(1)
    {
        cout << "\n===== STRING MENU =====" << endl;
        cout << "1. Display strings" << endl;
        cout << "2. Assignment" << endl;
        cout << "3. Concatenation (+)" << endl;
        cout << "4. Compare strings" << endl;
        cout << "5. Copy string" << endl;
        cout << "6. Reverse string" << endl;
        cout << "7. Uppercase" << endl;
        cout << "8. Lowercase" << endl;
        cout << "9. Find character" << endl;
        cout << "10. Find substring" << endl;
        cout << "11. String length" << endl;
        cout << "12. Compare first n characters (strncmp)" << endl;
        cout << "13. Exit" << endl;

        cout << "Enter choice: ";
        cin >> ch;

        switch(ch)
        {
            case 1:
                cout << "s1 = " << s1 << endl;
                cout << "s2 = " << s2 << endl;
                cout << "s3 = " << s3 << endl;
                break;

            case 2:
                s3 = s1;
                cout << "After assignment: " << s3 << endl;
                break;

            case 3:
            {
                String result = s1 + s2;
                cout << "Concatenation: " << result << endl;
                break;
            }

            case 4:
                cout << "s1 == s2: " << (s1 == s2) << endl;
                cout << "s1 != s2: " << (s1 != s2) << endl;
                cout << "s1 > s2: " << (s1 > s2) << endl;
                cout << "s1 < s2: " << (s1 < s2) << endl;
                break;

            case 5:
                strcpy(s3, s2);
                cout << "Copied string: " << s3 << endl;
                break;

            case 6:
                strrev(s3);
                cout << "Reversed string: " << s3 << endl;
                break;

            case 7:
                strupr(s3);
                cout << "Uppercase: " << s3 << endl;
                break;

            case 8:
                strlwr(s3);
                cout << "Lowercase: " << s3 << endl;
                break;

            case 9:
                p = strchr(s1, 't');
                if(p != nullptr)
                    cout << "Character found: " << p << endl;
                else
                    cout << "Character not found" << endl;
                break;

            case 10:
                p = strstr(s1, "tan");
                if(p != nullptr)
                    cout << "Substring found: " << p << endl;
                else
                    cout << "Substring not found" << endl;
                break;

            case 11:
                cout << "Length of s1: " << strlen(s1) << endl;
                break;

            case 12:
            {
                int n;

                cout << "Enter number of characters: ";
                cin >> n;

                cout << "strncmp: " << strncmp(s1, s2, n) << endl;
                break;
            }

            case 13:
                return 0;

            default:
                cout << "Invalid choice" << endl;
        }
    }
}



