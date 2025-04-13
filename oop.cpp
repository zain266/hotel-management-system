#include <iostream>
#include <cstring>
#include<string>
#include <fstream>
#include <sstream>
#include<curl/curl.h>
#include <cstdlib>
using namespace std;

void login()
{
	
    int attempts = 0;
    std::string username, password;
    const std::string correctUsername = "user";
    const std::string correctPassword = "pass";

    do
    {
        system("cls");
        cout<<"\t\t\t\t----------WELCOME TO OUR HOTEL------------\n\n";

        std::cout << "\n  *********  LOGIN FORM  *********  ";
        std::cout << "\n\n\nENTER USERNAME:-\n";
        std::cin >> username;
        std::cout << "\nENTER PASSWORD:-\n";
        std::cin >> password;

        if (username == correctUsername && password == correctPassword)
        {
            std::cout << "  \n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL";
            break;
        }
        else
        {
            std::cout << "\n        SORRY !!!!  LOGIN IS UNSUCCESSFUL\nPRESS ENTER TO TRY AGAIN";
            attempts++;
            std::cin.ignore(); // clear the input buffer
            std::cin.get(); // wait for user to press Enter
        }
    } while (attempts <= 2);

    if (attempts > 2)
    {
        std::cout << "\nSorry, you have entered the wrong username and password three times!!!";
        std::cin.get();
    }

    system("cls");
}

class Guest {
	private:
		string Name;
		string Address;
		string Phone;
		string checkIndate;
		string checkOutdate;
		int numdays;
		int guestIndex;
	public:
		Guest() {
		}

		Guest(const string n, const string addr, const string ph, const string checkin, const string checkout, int nd,int guest) {
			Name=n;
			Address=addr;
			Phone=ph;
			checkIndate=checkin;
			checkOutdate=checkout;
			numdays=nd;
			guestIndex=guest;
		}

		const string getName() {
			return Name;
		}

		const string getAddress() {
			return Address;
		}

		const string getPhone() {
			return Phone;
		}

		const string getcheckIndate() {
			return checkIndate;
		}

		const string getcheckOutdate() {
			return checkOutdate;
		}
		const int getguestIndex(){
			return guestIndex;
		}
};
class Room {
	private:
		int roomNumber;
		bool isOccupied;
	public:
		Room() {}

		Room(const int num) {
			roomNumber=num;
			isOccupied=false;
		}

		int getRoomNumber() const {
			return roomNumber;
		}

		bool getOccupancy() const {
			return isOccupied;
		}

		void occupyRoom() {
			isOccupied = true;
		}

		void vacateRoom() {
			isOccupied = false;
		}
};
class LuxuryRoom : public Room {
	private:
		float price;
	public:
		LuxuryRoom() {
			price=10000;
		}

		float getprice() {
			return price;
		}
};
class EconomyRoom : public Room {
	private:
		float price;
	public:
		EconomyRoom() {
			price=5000;
		}
		float getprice() {
			return price;
		}
};
class Employee {
	private:
		string EmployeeName;
		string Role;
		char Attendance[30];
		int employeeIndex;
	public:
		Employee() {
		}

		Employee(const string emp, const string r, int employee) {
			EmployeeName=emp;
			Role=r;
			for(int i=0; i<30; i++) {
				Attendance[i]='-';
			}
            employeeIndex=employee;
		}
		void addp(int day, char att) {
			this->Attendance[day] = att;
		}
		const string getEmployeeName() {
			return EmployeeName;
		}

		const string getRole() {
			return Role;
		}

		void getAttendance() {
			for(int i=0; i<30; i++) {
				cout<<Attendance[i]<<endl;
			}
		}
		
		int getemployeeIndex(){
			return employeeIndex;
		}
};
class InventoryItem {
	private:
		string ItemName;
		int Quantity;
	public:
		InventoryItem() {
		}

		InventoryItem(const string itname, const int q) {
			ItemName=itname;
			Quantity=q;
		}

		const string getItemName() {
			return ItemName;
		}

		const int getQuantity() {
			return Quantity;
		}
};

class service {

	private:
		int roomcleaning;
		int ironing;
		int laundary;
		int massage;

	public:
		service() {
			roomcleaning=4000;
			ironing=1100;
			laundary=1500;
			massage=7000;
		}

		int getroomcleaning() {
			return roomcleaning;
		}
		int getironing() {
			return ironing;
		}
		int getlaundary() {
			return laundary;
		}
		int getmassage() {
			return massage;
		}
};

class food {
	private:

		float tea;
		float coffee;
		float andaparhata;
		float waffle;
		float snacks;
		float hightea;
		float alfredopasta;
		float steak;
		float gravy;
		float roti;

	public:
		int tq, tc, ta, tw, ts, th, tap, tst, tg, tr;
		int *record;
		food() {
			tea=150;
			coffee=250;
			andaparhata=300;
			waffle=500;
			snacks=400;
			hightea=450;
			alfredopasta=1200;
			steak=1500;
			gravy=800;
			roti= 50;
			tq=0;
			tc=0;
			ta=0;
			tw=0;
			ts=0;
			th=0;
			tap=0;
			tst=0;
			tg=0;
			tr=0;
		}

		void setrecord(int n, int rec[]) {
			record= new int[n];

			for(int i=0; i<n; i++) {
				record[i]=rec[i];
			}
		}
		void setqtea(int q) {
			if(tq==0) {
				tq=tq+q;
			} else if(tq!=0) {
				tq=0;
				tq=tq+q;
			}
		}
		void setqcoffee(int c) {
			if(tc==0) {
				tc=tc+c;
			} else if(tc!=0) {
				tc=0;
				tc=tc+c;
			}
		}
		void setqandaparhata(int a) {
			if(ta==0) {
				ta=ta+a;
			} else if(ta!=0) {
				ta=0;
				ta=ta+a;
			}
		}
		void setqwaffle(int w) {

			if(tw==0) {
				tw=tw+w;
			} else if(tw!=0) {
				tw=0;
				tw=tw+w;
			}
		}
		void setqsnacks(int s) {

			if(ts==0) {
				ts=ts+s;
			} else if(ts!=0) {
				ts=0;
				ts=ts+s;
			}
		}
		void setqhightea(int h) {

			if(th==0) {
				th=th+h;
			} else if(th!=0) {
				th=0;
				th=th+h;
			}
		}
		void setqalfredopasta(int ap) {

			if(tap==0) {
				tap=tap+ap;
			} else if(tap!=0) {
				tap=0;
				tap=tap+ap;
			}
		}
		void setqsteak(int st) {

			if(tst==0) {
				tst=tst+st;
			} else if(tst!=0) {
				tst=0;
				tst=tst+st;
			}
		}
		void setqgravy(int g) {

			if(tg==0) {
				tg=tg+g;
			} else if(tg!=0) {
				tg=0;
				tg=tg+g;
			}
		}
		void setqroti(int r) {

			if(tr==0) {
				tr=tr+r;
			} else if(tr!=0) {
				tr=0;
				tr=tr+r;
			}
		}

		float gettea() {
			return tea;
		}
		float getcoffee() {
			return coffee;
		}
		float getandaparhata() {
			return andaparhata;
		}
		float getwaffle() {
			return waffle;
		}
		float getsnacks() {
			return snacks;
		}
		float gethightea() {
			return hightea;
		}
		float getalfredopasta() {
			return alfredopasta;
		}
		float getsteak() {
			return steak;
		}
		float getgravy() {
			return gravy;
		}
		float getroti() {
			return roti;
		}

};
// Class to represent the Hotel
class Hotel {
	private:
		static const int MAX_ROOMS = 100;
		Room rooms[MAX_ROOMS];
		Guest guests[MAX_ROOMS];
		Employee employees[50];
		LuxuryRoom luxrooms;
		food fd[MAX_ROOMS];
		service ser[MAX_ROOMS];
		int numRooms;
		int numEmployees;
		int numGuests;
		Guest guest;
		float totalPrice[MAX_ROOMS]= {0};

		int tq=0;
		int tc=0;
		int ta=0;
		int tw=0;
		int ts=0;
		int th=0;
		int tap=0;
		int tst=0;
		int tg=0;
		int tr=0;
		int p=0;


	public:
		Hotel() {
			numRooms=0;
			numGuests=0;
			numEmployees=0;
			// creates 100 rooms in the hotel
			for(int i=0; i<100; i++) {
				rooms[numRooms++] = Room(numRooms + 1);
			}
		}

		// Function to create an employee
		void addEmployee(string name, string role, int in) {
			employees[in] = Employee(name, role,in);

		}

		// Function to add employee attendance
		void attendance(int day, int in, char att) {
			employees[in].addp(day, att);
		}
		// Function to make reservation
		void MakeReservation(const string name, const string address, const string phone, const string checkin, const string checkout,int roomNumber, int guestIndex, int numdays) {
			// adds a new guest
			guests[numGuests++] = Guest(name, address, phone, checkin, checkout, numdays, guestIndex);
			// books a room
			rooms[roomNumber - 1].occupyRoom();
			cout << "Room " << roomNumber << " booked for guest " << guests[guestIndex].getName() << "\n";
		}

		void billing(int roomnumber, int numdays, int op[], int in, int q[], int nitem) {
			
			float fp;
			float sp;
			fd[in].setrecord(nitem, op);


			if(roomnumber<76 && roomnumber>=0) {
				p=numdays*5000;
				totalPrice[in]=totalPrice[in]+p;
			}

			if(roomnumber>75 && roomnumber<=100) {
				p=numdays*10000;
				totalPrice[in]=totalPrice[in]+p;
			}
			for(int i=0; i<nitem; i++) {
				if(op[i]==1) {
					fp=fd[in].gettea();
					tq=q[i];
					fd[in].setqtea(tq);
					fp=fp*q[i];
					totalPrice[in]=totalPrice[in]+fp;
				}
				if(op[i]==2) {
					fp=fd[in].getcoffee()*q[i];
					tc=q[i];
					fd[in].setqcoffee(tc);
					totalPrice[in]=totalPrice[in]+fp;
				}
				if(op[i]==3) {
					fp=fd[in].getandaparhata()*q[i];
					ta=q[i];
					fd[in].setqandaparhata(ta);
					totalPrice[in]=totalPrice[in]+fp;
				}
				if(op[i]==4) {
					fp=fd[in].getwaffle()*q[i];
					tw=q[i];
					fd[in].setqwaffle(tw);
					totalPrice[in]=totalPrice[in]+fp;
				}
				if(op[i]==5) {
					fp=fd[in].getsnacks()*q[i];
					ts=q[i];
					fd[in].setqsnacks(ts);
					totalPrice[in]=totalPrice[in]+fp;
				}
				if(op[i]==6) {
					fp=fd[in].gethightea()*q[i];
					th=q[i];
					fd[in].setqhightea(th);
					totalPrice[in]=totalPrice[in]+fp;
				}
				if(op[i]==7) {
					fp=fd[in].getalfredopasta()*q[i];
					tap=q[i];
					fd[in].setqalfredopasta(tap);
					totalPrice[in]=totalPrice[in]+fp;
				}
				if(op[i]==8) {
					fp=fd[in].getsteak()*q[i];
					tst=q[i];
					fd[in].setqsteak(tst);
					totalPrice[in]=totalPrice[in]+fp;
				}
				if(op[i]==9) {
					fp=fd[in].getgravy()*q[i];
					tg=q[i];
					fd[in].setqgravy(tg);
					totalPrice[in]=totalPrice[in]+fp;
				}
				if(op[i]==10) {
					fp=fd[in].getroti()*q[i];
					tr=q[i];
					fd[in].setqroti(tr);
					totalPrice[in]=totalPrice[in]+fp;
				}
				if(op[i]==11) {
					sp=ser[in].getroomcleaning();
					totalPrice[in]=totalPrice[in]+sp;
				}
				if(op[i]==12) {
					sp=ser[in].getironing();
					totalPrice[in]=totalPrice[in]+sp;
				}
				if(op[i]==13) {
					sp=ser[in].getlaundary();
					totalPrice[in]=totalPrice[in]+sp;
				}
				if(op[i]==14) {
					sp=ser[in].getmassage();
					totalPrice[in]=totalPrice[in]+sp;
				}

			}

			cout<<"your total price is: "<<totalPrice[in]<<endl;
		}

		string reciept(int in, int rec[], int q[], int nitem, int numdays, int roomnum) {
			stringstream ss;
			
			cout<<"-------------------------------reciept--------------------------------\n\n";
			ss<<"-------------------------------reciept--------------------------------\n\n";
			
			if(p!=0){
			cout<<"Room no. "<<roomnum<<" booked for "<<numdays<<"days\tTotal room charges are: "<<p<<endl<<endl;
			ss<<"Room no. "<<roomnum<<" booked for "<<numdays<<"days\tTotal room charges are: "<<p<<endl<<"\n";
			}
			else if(p==0){
				cout<<"No room booked.. if you want to stay kindly make reservation from the options. THANK YOU"<<endl<<endl;
				ss<<"No room booked.. if you want to stay kindly make reservation from the options. THANK YOU\n\n";
			}
			cout<<"items \t\t  quantity \t\t\t  price\n";
			ss<<"items \t\t  quantity \t\t\t  price\n";
			float t;
			for(int i=0; i<nitem; i++) {
				if(fd[in].record[i]==1) {
					t= fd[in].gettea()*fd[in].tq;
					cout<<i+1<<". tea\t\t\t "<<fd[in].tq<<"\t\t\t "<<"PKR "<<t<<endl;
					ss<<i+1<<". tea\t\t\t "<<fd[in].tq<<"\t\t\t "<<"PKR "<<t<<"\n";
				}
				if(fd[in].record[i]==2) {
					t= fd[in].getcoffee()*fd[in].tc;
					cout<<i+1<<". coffee\t\t "<<fd[in].tc<<"\t\t\t "<<"PKR "<<t<<endl;
					ss<<i+1<<". coffee\t\t "<<fd[in].tc<<"\t\t\t "<<"PKR "<<t<<"\n";

				}
				if(fd[in].record[i]==3) {
					t= fd[in].getandaparhata()*fd[in].ta;
					cout<<i+1<<". andaparhata\t\t "<<fd[in].ta<<"\t\t\t "<<"PKR "<<t<<endl;
					ss<<i+1<<". andaparhata\t\t "<<fd[in].ta<<"\t\t\t "<<"PKR "<<t<<"\n";
				}
				if(fd[in].record[i]==4) {
					t= fd[in].getwaffle()*fd[in].tw;
					cout<<i+1<<". twaffle\t\t "<<fd[in].tw<<"\t\t\t "<<"PKR "<<t<<endl;
					ss<<i+1<<". twaffle\t\t "<<fd[in].tw<<"\t\t\t "<<"PKR "<<t<<"\n";
				}
				if(fd[in].record[i]==5) {
					t= fd[in].getsnacks()*fd[in].ts;
					cout<<i+1<<". snacks\t\t "<<fd[in].ts<<"\t\t\t "<<"PKR "<<t<<endl;
					ss<<i+1<<". snacks\t\t "<<fd[in].ts<<"\t\t\t "<<"PKR "<<t<<"\n";
				}
				if(fd[in].record[i]==6) {
					t= fd[in].gethightea()*fd[in].th;
					cout<<i+1<<". hightea\t\t "<<fd[in].th<<"\t\t\t "<<"PKR "<<t<<endl;
					ss<<i+1<<". hightea\t\t "<<fd[in].th<<"\t\t\t "<<"PKR "<<t<<"\n";
					
				}
				if(fd[in].record[i]==7) {
					t= fd[in].getalfredopasta()*fd[in].tap;
					cout<<i+1<<". alfredopasta\t\t "<<fd[in].tap<<"\t\t\t "<<"PKR "<<t<<endl;
					ss<<i+1<<". alfredopasta\t\t "<<fd[in].tap<<"\t\t\t "<<"PKR "<<t<<endl;
				}
				if(fd[in].record[i]==8) {
					t= fd[in].getsteak()*fd[in].tst;
					cout<<i+1<<". steak\t\t "<<fd[in].tst<<"\t\t\t "<<"PKR "<<t<<endl;
					ss<<i+1<<". steak\t\t "<<fd[in].tst<<"\t\t\t "<<"PKR "<<t<<endl;
				}
				if(fd[in].record[i]==9) {
					t= fd[in].getgravy()*fd[in].tg;
					cout<<i+1<<". gravy\t\t "<<fd[in].tg<<"\t\t\t "<<"PKR "<<t<<endl;
					ss<<i+1<<". gravy\t\t "<<fd[in].tg<<"\t\t\t "<<"PKR "<<t<<endl;
				}
				if(fd[in].record[i]==10) {
					t= fd[in].getroti()*fd[in].tr;
					cout<<i+1<<". roti\t\t "<<fd[in].tr<<"\t\t\t "<<"PKR "<<t<<endl;
					ss<<i+1<<". roti\t\t "<<fd[in].tr<<"\t\t\t "<<"PKR "<<t<<endl;
				}
				if(fd[in].record[i]==11) {
					t= ser[in].getroomcleaning();
					cout<<i+1<<". room cleaning\t\t\t\t "<<"PKR "<<t<<endl;
					ss<<i+1<<". room cleaning\t\t\t\t "<<"PKR "<<t<<endl;
				}
				if(fd[in].record[i]==12) {
					t= ser[in].getironing();
					cout<<i+1<<". ironing\t\t\t\t\t "<<"PKR "<<t<<endl;
					ss<<i+1<<". ironing\t\t\t\t\t "<<"PKR "<<t<<endl;
				}
				if(fd[in].record[i]==13) {
					t= ser[in].getlaundary();
					cout<<i+1<<". laundary\t\t\t\t\t "<<"PKR "<<t<<endl;
					ss<<i+1<<". laundary\t\t\t\t\t "<<"PKR "<<t<<endl;
				}
				if(fd[in].record[i]==14) {
					t= ser[in].getmassage();
					cout<<i+1<<". message\t\t\t\t\t "<<"PKR "<<t<<endl;
					ss<<i+1<<". message\t\t\t\t\t "<<"PKR "<<t<<endl;
				}


			}
			cout<<"---------------------------------------------------------------------\n";
			cout<<"tax: %10"<<endl;
			cout<<"Total Price: "<<(totalPrice[in]*0.1)+totalPrice[in]<<endl;
			cout<<"---------------------------------------------------------------------\n";
			
			ss<<"---------------------------------------------------------------------\n";
			ss<<"tax: %10"<<endl;
			ss<<"Total Price: "<<(totalPrice[in]*0.1)+totalPrice[in]<<endl;
			ss<<"---------------------------------------------------------------------\n";
			return ss.str();
		}

		// Function to display available rooms
		void displayAvailableRooms() const {
			cout << "Available Rooms:\n";
			for (int i = 0; i < numRooms; ++i) {
				if (!rooms[i].getOccupancy()) {
					cout << "Room " << rooms[i].getRoomNumber() << "\n";
				}
			}
		}

		// Function to display employee details
		void displayemployee(int Eindex) {
			cout<<"----employee details------"<<endl;
			cout<<"name: "<<employees[Eindex].getEmployeeName()<<endl;
			cout<<"role: "<<employees[Eindex].getRole()<<endl;
			cout<<"------your attendance------"<<endl;
			employees[Eindex].getAttendance();
		}
		
			// Function to display guest details
		void displayGuestDetails(int guestindex){
			ifstream file2("guestdetails.txt", std::ios::in | std::ios::binary);
            if (!file2.is_open()) {
            std::cerr << "Error opening the file for reading." << std::endl;
            return;
        }
            file2.read(reinterpret_cast<char*>(&guest), sizeof(guest));
        while (!file2.eof()) {
            if (guestindex == guest.getguestIndex()) {
                cout << "Name: " << guest.getName() << std::endl;
                cout << "Address: " << guest.getAddress() << std::endl;
                cout << "Phone: " << guest.getPhone() << std::endl;
                cout << "Check-in Date: " << guest.getcheckIndate() << std::endl;
                cout << "Check-out Date: " << guest.getcheckOutdate() << std::endl;
            }
            file2.read(reinterpret_cast<char*>(&guest), sizeof(guest));
        }
        file2.close();
		}
		
		 // Function to add guest data to file
        void addguestdatatofile(int guestIndex){
          std::ofstream file1("guestdetails.txt", std::ios::app | std::ios::binary);
        if (!file1.is_open()) {
            std::cerr << "Error opening the file for writing." << std::endl;
            return;
        }
        file1.write(reinterpret_cast<char*>(&guests[guestIndex]), sizeof(guests[guestIndex]));
        file1.close();
	}
	
	 // Function to add employee data to file
        void addemployeedatatofile(int employeeIndex){
          std::ofstream file3("employeedetails.txt", std::ios::app | std::ios::binary);
        if (!file3.is_open()) {
            std::cerr << "Error opening the file for writing." << std::endl;
            return;
        }
        file3.write(reinterpret_cast<char*>(&employees[employeeIndex]), sizeof(employees[employeeIndex]));
        file3.close();
	}
};
// API functions
void displayMenu() {
//	cout<<"-------WELCOME TO OUR HOTEL-------\n";
	cout << "\n1. Make Reservation\n";
	cout << "2. Display Available Rooms\n";
	cout << "3. Display Guest Details\n";
	cout<<"4. Add Employee\n";
	cout<<"5. Add Employee attendance\n";
	cout<<"6. Add Menu Item/Services\n";
	cout << "7. Exit\n";
}

static size_t payload_index = 0;  // Global index to keep track of the payload position

size_t payload_source(void *ptr, size_t size, size_t nmemb, void *userp) {
    const char **payload_text = (const char **)userp;

    if(payload_text[payload_index] == nullptr) {
        return 0; // No more data to send
    }

    size_t len = strlen(payload_text[payload_index]);
    size_t room = size * nmemb;

    if (len > room) {
        return 0; // Not enough room for this block
    }

    memcpy(ptr, payload_text[payload_index], len);
    payload_index++;  // Move to the next part of the email content

    return len;
}

void sendEmail(const char* c, string email){
	const char * em = email.c_str();
	CURL *curl;
    CURLcode res = CURLE_OK;

    // Initialize global curl settings
    curl_global_init(CURL_GLOBAL_DEFAULT);

    // Initialize a curl handle
    curl = curl_easy_init();
    if(curl) {
        // SMTP server details
        curl_easy_setopt(curl, CURLOPT_URL, "smtp://smtp.gmail.com:587");
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, "k224623@nu.edu.pk");

        // Recipient
        struct curl_slist *recipients = NULL;
        recipients = curl_slist_append(recipients, em);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

        // Authentication
        curl_easy_setopt(curl, CURLOPT_USERNAME, "k224623@nu.edu.pk");
        curl_easy_setopt(curl, CURLOPT_PASSWORD, "}},,6Lh**");
        curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_TRY); // Use STARTTLS
        curl_easy_setopt(curl, CURLOPT_SSLVERSION, CURL_SSLVERSION_TLSv1_2);

        // Specify the path to CA certificates
        curl_easy_setopt(curl, CURLOPT_CAINFO, "C:\\Users\\areeb\\Downloads\\cacert-2023-08-22.pem");

        // Email content
        
     
        const char *payload_text[] = {
            "To: <",
			em,
			">\r\n",
            "From: <k224623@nu.edu.pk>\r\n",
            "Subject: Receipt From Hotel Communications\r\n",
            "\r\n",
            c,
            "\r\n",
            "\r\n.\r\n", // End-of-data indicator
            NULL
        };
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, payload_source);
        curl_easy_setopt(curl, CURLOPT_READDATA, (void *)payload_text);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L); // Enable data upload (sending email)

        // Enable verbose output for debugging
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

        // Send the email
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
        }

        payload_index = 0; // Reset the payload index

        // Clean up
        curl_slist_free_all(recipients);
        curl_easy_cleanup(curl);
    }

    // Clean up global curl settings
    curl_global_cleanup();
	
}
int main() {
	system("color F1");
	Hotel hotel;
	int choice;
	int Eindex;
	int roomNumber, numdays;
	int op;
	int opt;
	int indexx;
	int quantity;
	int iindex;
	int nitem;
	int day;
	int *rec;
	int *q;

	login();

	do {
		displayMenu();
		cout << "Enter your choice: ";
		cin >> choice;
		system("cls");
		switch (choice) {
			case 1: {
			    string name, address, phone, checkin, checkout;
				int guestIndex;
				fstream file1;

				cout << "Enter guest name: ";
				cin.ignore();
				getline(cin,name);

				cout << "Enter guest address: ";
				getline(cin,address);

				cout << "Enter guest phone: ";
				getline(cin,phone);

				cout<<"Enter number of days you want the room for: ";
				cin>>numdays;

				cout<<"Enter the type of room you want 1-75 are eco and 76-100 luxury: ";
				cin>>roomNumber;

				cout << "Enter guest check in date: ";
				cin.ignore();
				getline(cin,checkin);

				cout << "Enter guest check out date: ";
				getline(cin,checkout);

				cout << "Enter guest index: ";
				cin >> guestIndex;
				
				hotel.MakeReservation(name, address, phone,checkin, checkout,roomNumber, guestIndex, numdays);
				
				hotel.addguestdatatofile(guestIndex);
				break;
			}
			case 2:
				hotel.displayAvailableRooms();
				break;
			case 3:
				int guestIndex;
				cout << "Enter guest index: ";
				cin >> guestIndex;
				hotel.displayGuestDetails(guestIndex);
				break;
			case 4: {
				string Ename;
				string Erole;
				cout<<"enter your index: ";
				cin.ignore();
				cin>>Eindex;
				cout<<"enter employee name ";
				cin.ignore();
				cin>>Ename;
				cout<<"enter employee role ";
				cin.ignore();
				cin>>Erole;
				hotel.addEmployee(Ename, Erole, Eindex);
				hotel.addemployeedatatofile(Eindex);
				break;
			}
			case 5: {
				int index;
				char Eatt;
				cout<<"enter employee index for attendance: ";
				cin>>index;
				cin.ignore();
				cout<<"enter your attendance: ";
				cin>>Eatt;
				cin.ignore();
				cout<<"enter day number: ";
				cin>>day;
				cin.ignore();

				hotel.attendance(day, index, Eatt);
				hotel.addemployeedatatofile(Eindex);
				hotel.displayemployee(index);
				break;
			}
			case 6: {

				cout<<" --------------------------------\n";
				cout<<"|           ---MENU---           |\n";
				cout<<"|1.             tea              |\n";
				cout<<"|2.            coffee            |\n";
				cout<<"|3.          andaparhata         |\n";
				cout<<"|4.            waffle            |\n";
				cout<<"|5.            sancks            |\n";
				cout<<"|6.           hightea            |\n";
				cout<<"|7.         alfredo pasta        |\n";
				cout<<"|8.            steak             |\n";
				cout<<"|9.            gravy             |\n";
				cout<<"|10.            roti             |\n";
				cout<<" --------------------------------\n";
				cout<<" --------------------------------\n";
				cout<<"|         --Our Services--       |\n";
				cout<<"|11.       room cleaning         |\n";
				cout<<"|12.         ironing             |\n";
				cout<<"|13.         laundary            |\n";
				cout<<"|14.         massage             |\n";
				cout<<" --------------------------------\n";

				cout<<"enter your index ";
				cin>>indexx;
				cout<<"enter number of items you want: ";
				cin>>nitem;
				rec= new int[nitem];

				q= new int[nitem];

				for(int i=0; i<nitem; i++) {
					cout<<"Enter option from the menu: ";
					cin>>rec[i];
					if(rec[i]<11) {
						cout<<"Enter the quantity of your selected item: ";
						cin>>q[i];
					}
				}
				hotel.billing(roomNumber, numdays, rec, indexx, q, nitem);
				system("cls");
				int ind;
				cout<<"enter the index you want the reciept for: ";
				cin>>ind;
				string receiptEmail= hotel.reciept(ind, rec, q, nitem, numdays, roomNumber);
				const char* c= receiptEmail.c_str();
				cout<<"\n\nPlease write your email.."<<endl<<endl;
				string email;
				cin>> email;
				sendEmail(c, email);
				cout<<"\n\n Email sent succesfully\n\n";
				system("pause");
				system("cls");

				break;
			}
			default:
				ofstream file2;
				file2.open("guestdetails.txt",ios::trunc);
				file2.close();
				cout << "\n\n\t\t\tTHANK YOU FOR USING OUR SYSTEM. PLEASE DO COME AGAIN.\n\n";
		}
	} while (choice!=7);

	return 0;
}