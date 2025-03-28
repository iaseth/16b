#include <iostream>
#include <cstdint>



using namespace std;

class Date16
{
	uint16_t date;

public:
	// Encode a date into a 2-byte integer (YYYYYYYMMMMDDDDD)
	Date16 (int year, int month, int day) {
		if (year < 1970 || year > 2097) {
			throw invalid_argument("Year out of range (1970-2097)");
		}

		if (month < 1 || month > 12) {
			throw invalid_argument("Month out of range (1-12)");
		}

		if (day < 1 || day > 31) {
			throw invalid_argument("Day out of range (1-31)");
		}

		uint16_t year_bits = (year - 1970) & 0x7F; // 7 bits
		uint16_t month_bits = (month & 0x0F);      // 4 bits
		uint16_t day_bits = (day & 0x1F);          // 5 bits

		this->date = (year_bits << 9) | (month_bits << 5) | day_bits;
	}

	int value () { return this->date; }

	int year () { return 1970 + ((this->date >> 9) & 0x7F); }  // Extract 7 bits for year
	int month () { return (this->date >> 5) & 0x0F; }          // Extract 4 bits for month
	int day () { return this->date & 0x1F; }                   // Extract 5 bits for day
};

int main () {
	try {
		int year = 2025, month = 3, day = 28;

		// Encode the date
		Date16 date (year, month, day);
		cout << "Encoded: 0x" << hex << date.value() << " (" << dec << date.value() << ")" << endl;

		// Decode back
		cout << "Decoded: " << date.year() << "-" 
			 << date.month() << "-" 
			 << date.day() << endl;
	} catch (const exception &e) {
		cerr << "Error: " << e.what() << endl;
	}

	return 0;
}
