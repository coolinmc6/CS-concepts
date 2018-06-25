# Authentication Cheat Sheet Notes

[Back to all cheat sheet notes](https://github.com/coolinmc6/CS-concepts/tree/master/OWASP)

Based on OWASP's: [Authentication Cheat Sheet](https://www.owasp.org/index.php/Authentication_Cheat_Sheet)


### User IDs
1. Case insensitive
2. Email address as the UserID

### Passwords
The key concern is a **strong** password. The following criteria are **strong passwords**:

1. Minimum length of passwords (password length > 10 characters)
2. Maximum length cannot be too low (typical max length is 128 characters)
3. Password complexity should meet 3 of 4 criteria:
  	- at least 1 uppercase character (A-Z)
  	- at least 1 lowercase character (a-z)
  	- at least 1 digit (0-9)
  	- at least 1 special character (punctuation)
4. Ban commonly used passwords
5. Have secure password recovery mechanism
    - See [Forgot Password Cheat Sheet](https://www.owasp.org/index.php/Forgot_Password_Cheat_Sheet). 
6. Store passwords in a secure fashion
    - See [Password Storage Cheat Sheet](https://www.owasp.org/index.php/Password_Storage_Cheat_Sheet)
7. Transmit passwords only over TLS (HTTPS)
8. Require re-authentication for sensitive features like updating account information like user's password, email, or before sensitive transactions such as shipping to a new purchase address
9. Authentication and Error Messages
    - If login fails, keep message generic; "Login failed; invalid email/username or password."
10. Prevent Brute-Force Attacks
    - lockout system should be used to prevent further authentication attempts after some number of tries by locking the user out for some period of time (i.e. 20 minutes)
11. Logging and Monitoring
    - All app failures are logged and reviewed
    - All password failures are logged and reviewed
    - all accounts locked are logged and reviewed