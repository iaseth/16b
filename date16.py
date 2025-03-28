import struct



def encode_date(year: int, month: int, day: int) -> bytes:
	"""Encodes a date into exactly 2 bytes (YYYYYYYMMMMDDDDD format)."""
	if not (1970 <= year <= 2097):
		raise ValueError("Year out of range (1970-2097)")
	if not (1 <= month <= 12):
		raise ValueError("Month out of range (1-12)")
	if not (1 <= day <= 31):
		raise ValueError("Day out of range (1-31)")

	year_bits = (year - 1970)  # 7 bits
	month_bits = month         # 4 bits
	day_bits = day             # 5 bits

	encoded = (year_bits << 9) | (month_bits << 5) | day_bits
	return struct.pack(">H", encoded)  # Store as exactly 2 bytes (big-endian)

def decode_date(encoded_bytes: bytes) -> tuple:
	"""Decodes a 2-byte encoded date back into (year, month, day)."""
	encoded = struct.unpack(">H", encoded_bytes)[0]  # Convert bytes to int
	year = 1970 + ((encoded >> 9) & 0b1111111)  # Extract 7 bits for year
	month = (encoded >> 5) & 0b1111             # Extract 4 bits for month
	day = encoded & 0b11111                     # Extract 5 bits for day
	return year, month, day

# Example usage
encoded_bytes = encode_date(2025, 3, 28)
print(f"Encoded (hex): {encoded_bytes.hex()}")  # Prints exactly 2 bytes

decoded_date = decode_date(encoded_bytes)
print(f"Decoded: {decoded_date}")  # (2025, 3, 28)
