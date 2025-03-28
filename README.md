# 16b: A Compact 16-Bit Date Representation

## Overview
**16b** is a lightweight and efficient library for encoding and decoding dates using only **16 bits (2 bytes)**. This allows compact storage and fast manipulation of dates, making it ideal for embedded systems, databases, and performance-critical applications.

## Date Format (Bit Layout)
The 16-bit date is structured as follows:

```
YYYYYYYMMMMDDDDD
```

- **7 bits** for the year (offset from 1970, supports 1970-2097)
- **4 bits** for the month (1-12)
- **5 bits** for the day (1-31)

This format ensures efficient encoding of common date values within a **2-byte integer**.

## Supported Languages
- **C** (`c/date16.c`)
- **C++** (`cpp/date16.cpp`)
- **Python** (`python/date16.py`)

## Installation
Clone the repository:
```sh
git clone https://github.com/iaseth/16b.git
cd 16b
```

### C/C++
Compile with:
```sh
gcc -o 16b c/date16.c   # For C
g++ -o 16b cpp/date16.cpp # For C++
```
Run the executable:
```sh
./16b
```

### Python
```sh
cd python
python3 date16.py
```

## Usage
### Encoding Example (C++)
```cpp
int year = 2025, month = 3, day = 28;

// Encode the date
Date16 date (year, month, day);
cout << "Encoded: 0x" << hex << date.value() << " (" << dec << date.value() << ")" << endl;

// Decode back
cout << "Decoded: " << date.year() << "-" 
	 << date.month() << "-" 
	 << date.day() << endl;
```
### Decoding Example (Python)
```python
encoded_bytes = encode_date(2025, 3, 28)
print(f"Encoded (hex): {encoded_bytes.hex()}")  # Prints exactly 2 bytes

decoded_date = decode_date(encoded_bytes)
print(f"Decoded: {decoded_date}")  # (2025, 3, 28)
```

## License
This project is licensed under the MIT License.

## Contact
For questions, open an issue or reach out via GitHub Discussions.
