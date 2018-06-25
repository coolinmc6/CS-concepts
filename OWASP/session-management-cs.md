[Back to all cheat sheet notes](https://github.com/coolinmc6/CS-concepts/tree/master/OWASP)

# Session Management Cheat Sheet Notes

Based on OWASP's: [Session Management Cheat Sheet](https://www.owasp.org/index.php/Session_Management_Cheat_Sheet)

### Intro
- a web session is a sequence of network HTTP request and response transactions associated to the same user
- Sessions provide the ability to establish variables (i.e. access rights and localization settings), which will apply to each and every interaction a user has with the web application for the duration of the session
- web applications can also create sessions to keep track of anonymous users after the very first user request
- current web apps can provide session capabilities pre and post-authentication
- once an authenticated session has been established, the session ID (or token) is **temporarily equivalent to** the strongest authentication method used by the application
- HTTP is a stateless protocol (each request is independent of other web interactions)
- the session ID or token binds the user auth credentials (in the form of a session) to the user HTTP traffic and the appropriate access controls enforced by the web application

### Session ID Properties
- to track the user, the web app provides the user with a session identifier (session ID or token) that is assigned at creation time and is shared/exchanged by user and web app for entire session
- the session ID is a "name=value" pair
- the name for the session ID should not be extremely descriptive about the purpose or meaning of the ID
- the session ID length must be **long enough** to prevent brute force attacks
- session ID length must be at **least 128 bits (16 bytes)** => minimum 16 characters
- session ID must be **unpredictable** (random enough) to prevent guessing attacks
- session ID content / value must be **meaningless**
	+ all the application logic associated with the session ID must be stored on the server side, information like: client IP address, username, userID, role, access rights, account ID, current state, last login, etc.
	+ For example, the cookie has the session ID while the session object has the userID, email, and other user info

### Session Management Implementation
- the *session management implementation* defines how the user and the web application continuously share the session ID.
- There are a number of ways in HTTP to maintain session state within the application such as:
	+ cookies (standard HTTP header)
	+ URL parameters
	+ URL arguments on GET requests
	+ body arguments on POST requests (i.e. hidden form fields (HTML forms))
	+ proprietary HTTP headers
- the **preferred session ID** exchange mechanism should allow developers to set advanced token properties like:
	+ expiration date and time
	+ granular usage constraints
- **this is why cookies are one of the most extensively used session ID exchange mechanisms**
- use HTTPS for the entire web session
- Must use the "secure" cookie attribute to ensure the session ID is only exchanged through an encrypted channel
	- see the [Transport Layer Protection Cheat Sheet](https://www.owasp.org/index.php/Transport_Layer_Protection_Cheat_Sheet) for more information

### Cookies
