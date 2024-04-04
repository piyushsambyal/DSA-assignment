/*
Design a contact list program. It is a simple console base
application with no visuals. It's similar to contact application
you see in your mobile phones. Following are the essential
elements of a contact List Application:
1. Add new contacts, including their name, phone
number, company, and email address.
2. List all contacts: displays a list of all the contacts,
along with their contact information.
3. Search Contacts: Contacts may be found by
searching by name and phone number.
4. Edit contacts: Make changes to the information
provided when adding contacts, such as name,
phone number, address, and email address.
5. Delete contacts: removes contacts from the list
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define MAX_STR_LEN 65

struct Contact {
	char name[MAX_STR_LEN];
	char number[MAX_STR_LEN];
	char company[MAX_STR_LEN];
	char email[MAX_STR_LEN];
};

typedef struct Contact contact_t;

#define MAX_CONTACT_SIZE 64
contact_t contacts[64];
size_t size = 0;

void printContact(contact_t *contact) {
	printf("Name: %s\n", contact->name);
	printf("Phone Number: %s\n", contact->number);
	printf("Email: %s\n", contact->email);
	printf("Company: %s\n", contact->company);
}

void add() {
	if (size + 1 >= MAX_CONTACT_SIZE) {
		printf("Contact list is full...\n");
		return;
	}
	char buffer[MAX_STR_LEN];
	printf("Enter Phone number to add: ");
	scanf("\n%[^\n]64s", buffer);
	for (size_t i = 0; i < size; i++) {
		if (strcasecmp(contacts[i].number, buffer) == 0) {
			printf("Phone number already exists in contact list\n");
			return;
		}
	}
	contact_t *c = &contacts[size++];
	strcpy(c->number, buffer);

	printf("Enter name: ");
	scanf("\n%[^\n]64s", buffer);
	strcpy(c->name, buffer);

	printf("Enter Email: ");
	scanf("\n%[^\n]64s", buffer);
	strcpy(c->email, buffer);

	printf("Enter Company: ");
	scanf("\n%[^\n]64s", buffer);
	strcpy(c->company, buffer);
}

void search() {
	char buffer[MAX_STR_LEN];
	printf("Enter search term: ");
	scanf("\n%[^\n]64s", buffer);
	size_t len = strlen(buffer);

	printf("Matches....\n");
	for (size_t i = 0; i < size; i++) {
		if (strncasecmp(contacts[i].name, buffer, len) == 0 ||
		    strncasecmp(contacts[i].number, buffer, len) == 0 ||
		    strncasecmp(contacts[i].email, buffer, len) == 0 ||
		    strncasecmp(contacts[i].company, buffer, len) == 0) {
			printf("Contact Number %lu\n", i + 1);
			printContact(&contacts[i]);
			printf("====\n");
		}
	}
	printf("====\n");
}

void edit() {
	int idx;
	printf("Enter Entry number to edit: ");
	scanf("\n%d", &idx);
	if (idx <= 0 || idx > size) {
		printf("Number out of bounds!!!\n");
		return;
	}
	contact_t *c = contacts + idx - 1;
	char buffer[MAX_STR_LEN];
	printf("Enter Name: ");
	scanf("\n%[^\n]64s", buffer);
	if (strlen(buffer) != 0) strcpy(c->name, buffer);

	printf("Enter Phone number: ");
	scanf("\n%[^\n]64s", buffer);
	if (strlen(buffer) != 0) strcpy(c->number, buffer);

	printf("Enter Email: ");
	scanf("\n%[^\n]64s", buffer);
	if (strlen(buffer) != 0) strcpy(c->email, buffer);

	printf("Enter Company: ");
	scanf("\n%[^\n]64s", buffer);
	if (strlen(buffer) != 0) strcpy(c->company, buffer);
}

void delete() {
	int idx;
	printf("Enter entry number to delete\n");
	scanf("\n%d", &idx);
	if (idx <= 0 || idx > size) {
		printf("Number out of bounds!!!\n");
		return;
	} else {
		for (int i = idx - 1; i < size - 1; i++) {
			contacts[i] = contacts[i + 1];
		}
		size--;
	}
}

void display() {
	for (int i = 0; i < size; i++) {
		printContact(contacts + i);
		printf("===\n");
	}
}

void stdin_flush() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF)
		;
}

int main() {
	while (1) {
		int op = 0;
		printf("\033[H\033[J");
		printf("Available Operations\n");
		printf("1) Add Contact\n");
		printf("2) List Contacts\n");
		printf("3) Edit Contact\n");
		printf("4) Search Contacts\n");
		printf("5) Delete Contacts\n");
		printf("6) Exit\n");
		printf("Enter Operation: ");
		scanf("\n%d", &op);

		switch (op) {
		case 1: add(); break;
		case 2: display(); break;
		case 3: edit(); break;
		case 4: search(); break;
		case 5: delete (); break;
		case 6: exit(0);
		default: break;
		}
		printf("Press Enter to continue...");
		stdin_flush();
		getchar();
	}
}