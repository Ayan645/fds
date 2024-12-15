#include<iostream>
using namespace std;

typedef struct Appointment{
	struct Appointment *prev;
	int tokenID;
	string Name;
	int hourOfDay;
	int startTime;
	int endTime;
	int minDuration;
	int maxDuration;
	bool booked;
	struct Appointment *next;
}APPT;

// Theory: This structure represents an appointment slot with details like token ID, visitor name, time slots, durations, and booking status.

class AppointmentSchedular{
	private:
		APPT *head,*tail;
		int countID;
	public:
		AppointmentSchedular(){
			head = NULL;
			tail = NULL;
			countID = 0;
		}

		void addFreeSlot(int hod, int stime, int etime, int min, int max){
			APPT *p = new APPT;
			p->prev = NULL;
			p->tokenID = ++countID;
			p->Name = "";
			p->hourOfDay = hod;
			p->startTime = stime;
			p->endTime = etime;
			p->minDuration = min;
			p->maxDuration = max;
			p->booked = false;
			p->next = NULL;

			if(head == NULL)
				head = tail = p;
			else{
				tail->next = p;
				p->prev = tail;
				tail = p;
			}
		}

// Theory: Adds a new free slot to the linked list with specified time and duration details.

		void displayList(){
			APPT *cur = head;
			cout << "\nID\tName\tHoday\tsTime\teTime\tminD\tmaxD\tBooked";
			while(cur != NULL){
				cout << "\n" << cur->tokenID << "\t" << cur->Name << "\t" << cur->hourOfDay << "\t" << cur->startTime << "\t" << cur->endTime << "\t" << cur->minDuration << "\t" << cur->maxDuration << "\t" << cur->booked;
				cur = cur->next;
			}
			cout << "\n->NULL";
		}

// Theory: Displays all appointment slots, including their details such as ID, name, times, and booking status.

		void bookAppointment(int id, string name){
			APPT *cur = head;
			while(cur != NULL){
				if(cur->tokenID == id){
					if(cur->booked == false){
						cur->Name = name;
						cur->booked = true;
					}
					else
						cout << "\nSlot already booked";
					break;
				}
				cur = cur->next;
			}
			if(cur == NULL)
				cout << "\nNo slot " << id << " available";
		}

// Theory: Books an appointment by marking a slot as booked and assigning the visitor's name, provided the slot is available.

		void sortList(){
			APPT *i, *j, *temp = new APPT;
			for(i = head; i != NULL; i = i->next){
				for(j = i->next; j != NULL; j = j->next){
					if(i->hourOfDay > j->hourOfDay){
						temp->tokenID = i->tokenID;
						temp->Name = i->Name;
						temp->hourOfDay = i->hourOfDay;
						temp->startTime = i->startTime;
						temp->endTime = i->endTime;
						temp->minDuration = i->minDuration;
						temp->maxDuration = i->maxDuration;
						temp->booked = i->booked;

						i->tokenID = j->tokenID;
						i->Name = j->Name;
						i->hourOfDay = j->hourOfDay;
						i->startTime = j->startTime;
						i->endTime = j->endTime;
						i->minDuration = j->minDuration;
						i->maxDuration = j->maxDuration;
						i->booked = j->booked;

						j->tokenID = temp->tokenID;
						j->Name = temp->Name;
						j->hourOfDay = temp->hourOfDay;
						j->startTime = temp->startTime;
						j->endTime = temp->endTime;
						j->minDuration = temp->minDuration;
						j->maxDuration = temp->maxDuration;
						j->booked = temp->booked;
					}
				}
			}
		}

// Theory: Sorts the appointment slots based on the hour of the day in ascending order by swapping the data fields.

};

int main(){
	int choice = 0;
	string name;
	int hod, stime, etime, min, max, id;
	AppointmentSchedular sch;
	while(choice != 6){
		cout << "\n***************APPOINTMENT SCHEDULER*****************";
		cout << "\n1. Add free slots";
		cout << "\n2. Display free slots ";
		cout << "\n3. Book appointment";
		cout << "\n4. Sort list based on time";
		cout << "\n5. Sort list based on time using pointer manipulation";
		cout << "\n6. Exit Application";
		cout << "\nWhat is your choice::";
		cin >> choice;
		switch(choice){
			case 1:
				cout << "\nEnter hour of a day (0 to 23):";
				cin >> hod;
				cout << "\nEnter start time of an hour:";
				cin >> stime;
				cout << "\nEnter end time of an hour:";
				cin >> etime;
				cout << "\nEnter minimum duration as minutes:";
				cin >> min;
				cout << "\nEnter maximum duration as minutes:";
				cin >> max;
				sch.addFreeSlot(hod, stime, etime, min, max);
				break;
			case 2:
				sch.displayList();
				break;
			case 3:
				sch.displayList();
				cout << "\nEnter slot number to be booked:";
				cin >> id;
				cout << "\nEnter your Name:";
				cin >> name;
				sch.bookAppointment(id, name);
				break;
			case 4:
				sch.sortList();
				break;
			case 6:
				cout << "\nGood Bye!!";
				break;
			default:
				cout << "\nInvalid Choice!";
		}
	}
	return 0;
}

// Theory: The main function serves as a menu-driven interface to perform operations such as adding slots, booking appointments, displaying free slots, and sorting based on time.
