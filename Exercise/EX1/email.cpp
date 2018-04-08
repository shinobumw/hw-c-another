#include <bits/stdc++.h>
using namespace std;

struct Email {
    char name[100];
    char domain[100];
};

int myStrcmp(char p[], char q[])
{
    for (int i = 0; p[i] || q[i]; ++i) {
        if (tolower(p[i]) != tolower(q[i]))
            return (tolower(p[i]) - tolower(q[i]));
    }
    return 0;
}

// Return true if p before q.
bool cmpName(Email &p, Email &q)
{
    return (myStrcmp(p.name, q.name) < 0);
}

bool cmpDomain(Email &p, Email &q)
{
    if (myStrcmp(p.domain, q.domain) == 0)
        return (myStrcmp(p.name, q.name) < 0);
    else 
        return (myStrcmp(p.domain, q.domain) < 0);
}

void sol(int n) 
{
    Email addr[100];
    char line[210];
    char valid[10]=".@_";    // Valid characters
    int count = 0;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        fgets(line, 200, stdin);
        line[strlen(line)-1] = '\0';     // overwrite the end of line.

        // Check invalid character
        char *s = line;
        for (; *s; ++s) {
            if (!isalpha(*s) && !isdigit(*s) && strchr(valid, *s) == NULL)
                break;
        }
        if (*s) {
            cout << "\"" << line << "\"" << " includes invalid character." << '\n';
            continue;
        }

        // Find the first @
        char *p = strchr(line, '@');
        if (p == NULL) {
            cout << "\"" << line << "\"" << " is not a valid address, lacking of @." << '\n';
            continue;
        }
        // Break line into two string separated by found @.
        strncpy(addr[count].name, line, p - line);
        addr[count].name[p-line] = '\0';
        strcpy(addr[count].domain, p + 1);

        // Check invalid username
        if (addr[count].name[0] == '\0') {
            cout << "\"" << line << "\"" << " includes invalid username." << '\n';
            continue;
        }

        p = strstr(addr[count].name, ".");
        if (p != NULL) {
            p = strstr(p + 1, ".");
            if  (p != NULL) {
                cout << "\"" << line << "\"" << " includes invalid username." << '\n';
                continue;
            }
        }
        
        // Check invalid domain
        if (strchr(addr[count].domain, '@') != NULL) {
            cout << "\"" << line << "\"" << " includes too many @." << '\n';
            continue;
        }

        int len_domain = strlen(addr[count].domain);
        if (addr[count].domain[len_domain-1] == '.') {
            cout << "\"" << line << "\"" << " includes invalid domain." << '\n';
            continue;
        }

        p = strstr(addr[count].domain, ".");
        if (p != NULL) {
            do {
                if  (*(p+1) == '.') {
                    cout << "\"" << line << "\"" << " includes invalid domain." << '\n';
                    continue;
                }
                p = strstr(p + 1, ".");
            } while (p != NULL);
        }

        count++;
    }
    
    cout << '\n';
    /*
    cout << "Print valid address:" << '\n';
    for (int i = 0; i < count; i++)
        printf("%d. %s@%s\n", i + 1, addr[i].name, addr[i].domain);
    cout << '\n';
    */
    if (count > 0) {
        // Sorted by username
        sort(addr, addr + count, cmpName);
        cout << "(i) Sorted by username:" << '\n';
        for (int i = 0; i < count; ++i)
            printf("%s@%s\n", addr[i].name, addr[i].domain);
        cout << '\n';
        // Sorted by domain + username
        sort(addr, addr + count, cmpDomain);
        cout << "(ii) Sorted by domain + username:" << '\n';
        for (int i = 0; i < count; ++i)
            printf("%s@%s\n", addr[i].name, addr[i].domain);
        cout << '\n';
    }
}

int main()
{
    freopen("false.in", "r", stdin);
    while (1) {
        int n;
        cin >> n;
        if (n == 0) break;
        sol(n);
    }
    return 0;
}