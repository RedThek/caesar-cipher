def encrypt(text, key):
   
    UPPER = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    LOWER = 'abcdefghijklmnopqrstuvwxyz'
    result = ''
    for char in text:
        if char.isupper():
            result += UPPER[(UPPER.index(char) + key) % 26]
        elif char.islower():
            result += LOWER[(LOWER.index(char) + key) % 26]
        else:
            result += char
    return result

def decrypt(text, key):

    return encrypt(text, -key)

if __name__ == "__main__":
    original = "Hello, World! ABCxyz"
    key = 3
    encrypted = encrypt(original, key)
    decrypted = decrypt(encrypted, key)
    print(f"Original: {original}")
    print(f"Encrypted: {encrypted}")
    print(f"Decrypted: {decrypted}")
