#include <stdio.h>
#include <stdint.h>



typedef uint16_t Date16; // 2-byte date format

typedef struct DateStruct {
	int year, month, day;
} DateStruct;


// Encode a date into a 2-byte integer (YYYYYYYMMMMDDDDD)
Date16 encode_date (int year, int month, int day) {
	if (year < 1970 || year > 2097) {
		printf("Year out of range (1970-2097)\n");
		return 0;
	}

	if (month < 1 || month > 12) {
		printf("Month out of range (1-12)\n");
		return 0;
	}

	if (day < 1 || day > 31) {
		printf("Day out of range (1-31)\n");
		return 0;
	}

	uint16_t year_bits = (year - 1970) & 0x7F; // 7 bits
	uint16_t month_bits = (month & 0x0F);      // 4 bits
	uint16_t day_bits = (day & 0x1F);          // 5 bits

	return (year_bits << 9) | (month_bits << 5) | day_bits;
}

// Decode a 2-byte integer into (year, month, day)
DateStruct decode_date (Date16 encoded) {
	DateStruct date;
	date.year = 1970 + ((encoded >> 9) & 0x7F);  // Extract 7 bits for year
	date.month = (encoded >> 5) & 0x0F;          // Extract 4 bits for month
	date.day = encoded & 0x1F;                   // Extract 5 bits for day
	return date;
}

int main () {
	int year = 2025, month = 3, day = 28;

	// Encode the date
	Date16 encoded = encode_date(year, month, day);
	printf("Encoded: 0x%04X (%u)\n", encoded, encoded);

	// Decode back
	DateStruct date = decode_date(encoded);
	printf("Decoded: %d-%02d-%02d\n", date.year, date.month, date.day);

	return 0;
}
