
def encode_date(year: int, month: int, day: int) -> int:
	"""Encodes a date into a 2-byte integer (YYYYYYYMMMMDDDDD format)."""
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
	return encoded

def decode_date(encoded: int) -> tuple:
	"""Decodes a 2-byte integer back into (year, month, day)."""
	year = 1970 + ((encoded >> 9) & 0b1111111)  # Extract 7 bits for year
	month = (encoded >> 5) & 0b1111             # Extract 4 bits for month
	day = encoded & 0b11111                     # Extract 5 bits for day

	return year, month, day

# Example usage
encoded_value = encode_date(2025, 3, 28)
print(f"Encoded: {encoded_value:016b} ({encoded_value})")

decoded_date = decode_date(encoded_value)
print(f"Decoded: {decoded_date}")  # (2025, 3, 28)
