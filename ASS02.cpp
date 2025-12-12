#include <iostream>
#include <string>
using namespace std;

struct Post {
    string message;
    string privacy;
    string date;
    Post* next;
    Post* prev;
};
Post* head = NULL;
Post* tail = NULL;
Post* current = NULL;

void addNewPost() {
    Post* newPost = new Post;

    cin.ignore();
    cout << "\nEnter message: ";
    getline(cin, newPost->message);
    cout << "Share with (Public/Friends/Private): ";
    getline(cin, newPost->privacy);
    cout << "Enter date (dd-mm-yyyy): ";
    getline(cin, newPost->date);

    newPost->next = NULL;
    newPost->prev = tail;

    if (head == NULL) {
        head = newPost;
    } else {
        tail->next = newPost;
    }

    tail = newPost;
    cout << "\n? New post added successfully!\n";
}

void showPost(Post* p) {
    if (p == NULL) return;

    cout << "\n--------------------------------------\n";
    cout << "Message: " << p->message << endl;
    cout << "Privacy: " << p->privacy << endl;
    cout << "Date: " << p->date << endl;
    cout << "--------------------------------------\n";
}

void editPost(Post* p) {
    if (p == NULL) return;

    cin.ignore();
    cout << "\nEditing this post:\n";
    cout << "Enter new message: ";
    getline(cin, p->message);
    cout << "Enter new privacy (Public/Friends/Private): ";
    getline(cin, p->privacy);
    cout << "Enter new date: ";
    getline(cin, p->date);

    cout << "\n? Post updated successfully!\n";
}
void deletePost(Post*& p) {
    if (p == NULL) return;

    if (p->prev == NULL)
        head = p->next;
    else
        p->prev->next = p->next;

    if (p->next == NULL)
        tail = p->prev;
    else
        p->next->prev = p->prev;

    Post* temp = p;
    p = p->next;
    delete temp;

    cout << "\n??? Post deleted successfully!\n";
}
void viewByPrivacy() {
    if (head == NULL) {
        cout << "\nNo posts to show!\n";
        return;
    }

    string type;
    cout << "\nEnter privacy to filter (Public/Friends/Private): ";
    cin >> type;

    Post* temp = head;
    bool found = false;

    cout << "\n=== Posts with privacy: " << type << " ===\n";

    while (temp != NULL) {
        if (temp->privacy == type) {
            showPost(temp);
            found = true;
        }
        temp = temp->next;
    }

    if (!found)
        cout << "No posts found with this privacy.\n";
}

void viewAllPosts() {
    if (head == NULL) {
        cout << "\nNo posts available!\n";
        return;
    }
    cout << "\n=== All Posts ===\n";
    Post* temp = head;

    while (temp != NULL) {
        showPost(temp);
        temp = temp->next;
    }
}
void viewPosts() {
    if (head == NULL) {
        cout << "\nNo posts to show!\n";
        return;
    }

    current = head;
    showPost(current);

    char option;

    while (true) {
        cout << "\nPress N = Next | P = Previous | E = Edit | D = Delete | Q = Quit: ";
        cin >> option;
        option = tolower(option);

        if (option == 'n') {
            if (current->next != NULL) {
                current = current->next;
                showPost(current);
            } else {
                cout << "?? No newer post.\n";
            }
        }
        else if (option == 'p') {
            if (current->prev != NULL) {
                current = current->prev;
                showPost(current);
            } else {
                cout << "?? No older post.\n";
            }
        }
        else if (option == 'e') {
            editPost(current);
        }
        else if (option == 'd') {
            deletePost(current);
            if (head == NULL) {
                cout << "All posts deleted!\n";
                break;
            } else if (current == NULL) {
                current = head;
            }
        }
        else if (option == 'q') {
            break;
        }
        else {
            cout << "? Invalid option!\n";
        }
    }
}

int main() {
    int choice;
while (true) {
    cout << "\n========== SOCIAL NETWORK MENU ==========\n";
    cout << "1. New Post\n";
    cout << "2. View Posts\n";
    cout << "3. View by Privacy\n";
    cout << "4. View All Posts\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

if (choice == 1)
            addNewPost();
        else if (choice == 2)
            viewPosts();
        else if (choice == 3)
            viewByPrivacy();
        else if (choice == 4)
            viewAllPosts();
        else if (choice == 5) {
            cout << "\nThank you . Goodbye!\n";
            break;
        }
        else
            cout << "\nInvalid choice! Please try again.\n";
    }

    return 0;
}