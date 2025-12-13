import java.util.Scanner;

public class main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the message: ");
        String message = scanner.nextLine();
        System.out.print("Enter the key: ");
        int key = scanner.nextInt();
        System.out.print("Choose (E)ncrypt or (D)ecrypt: ");
        char choice = scanner.next().charAt(0);
        scanner.close();
        main caesarCipher = new main();
        if (choice == 'E' || choice == 'e') {
            String encryptedMessage = caesarCipher.caesarEncrypt(message, key);
            System.out.println("Encrypted message: " + encryptedMessage);
        } else if (choice == 'D' || choice == 'd') {
            String decryptedMessage = caesarCipher.caesarDecrypt(message, key);
            System.out.println("Decrypted message: " + decryptedMessage);
        } else {
            System.out.println("Invalid choice!");
        }
    }

    public String caesarEncrypt(String message, int key) {
        int alphabetSize = 26;
        StringBuilder encrypted = new StringBuilder();
        for (int i = 0; i < message.length(); i++) {
            char ch = message.charAt(i);
            if (Character.isLetter(ch)) {
                char base = Character.isLowerCase(ch) ? 'a' : 'A';
                int shifted = (ch - base + key) % alphabetSize;
                encrypted.append((char)(base + shifted));
            } else {
                encrypted.append(ch);
            }
        }
        return encrypted.toString();
    }

    public String caesarDecrypt(String message, int key) {
        int alphabetSize = 26;
        return caesarEncrypt(message, alphabetSize - key);
    }
}