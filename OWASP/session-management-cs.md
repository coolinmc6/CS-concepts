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
- Secure Attribute
	+ the "secure" cookie attribute instruct web browsers to only send the cookie through an encrypted HTTPS (SSL/TLS) connection
+ HttpOnly Attribute
	* the "HttpOnly" cookie attribute instructs web browsers not to allow scripts (i.e. JavaScript or VBscript) an ability to access the cookies via the DOM `document.cookie` object
	* this protection is **mandatory** to prevent session ID stealing through XSS attacks
	* see [XSS (Cross Site Scripting) Prevention Cheat Sheet](https://www.owasp.org/index.php/XSS_(Cross_Site_Scripting)_Prevention_Cheat_Sheet) for more
	* `setCookie("sessionID", "good_session_id", time()+600, "/", "example.com", FALSE,TRUE);`
		- `session` is the name of the cookie key
		- `good_session_id` => the value of that key
		- `time()+600` => expires in 600 seconds or 10 minutes
		- `example.com` => the domain
		- Secure attribute is set to `FALSE`
		- HttpOnly attribute is set to `TRUE`
+ SameSite Attribute
	* SameSite allows a server to define a cookie attribute making it impossible for the browser to send this cookie along with cross-site requests
+ Domain and Path Attributes
+ Expire and Max-Age Attributes
	* use non-persistent cookies for session management purposes so that the session ID does not remain on the web client cache for long periods of time, from where an attacker can obtain it

### Session ID Life Cycle

- Session IDs must be considered untrusted and thoroughly validated and verified
- renew the session ID after any privelege level change (i.e. user changes from unauthenticated state to authenticated state); 
	- here are some examples:
		* logins (unauth -> auth)
		* password changes
		* permission changes
	- session ID regeneration is mandatory to prevent session fixation attacks
* Considerations When Using Multiple Cookies
	- if multiple cookies for a given session, the web app must verify all cookies

### Session Expiration
- to invalidate a cookie, it is common to provide an empty value for the session ID and set "Expires" date to a date from the past.
- Automatic Session Expiration
	+ all sessions should implement an idle or inactvity timeout
		* session timeout management and expiration must be enforced server-side
	+ all sessions should implement an absolute timeout => a maximum amount of time a session can be active
		* after which a session is closed and the user is forced to (re)authenticate again in the web application and establish a new session
			- does FB do this? Twitter?
	+ **Alternatively**, the web app can implement an additional renewal timeout where the session ID is automatically renewed in the middle of the user session
	+ Manual session expiration => logout button
	+ Web Content Caching
		* prevent the private or sensitive data within the session to be kept in the web browser cache:
			- "Cache-Control: no-cache,no-store" (HTTP Headers) and
			- "Pragma: no-cache" (HTTP Headers)

### Session Attacks Detection
- Session ID Guessing and Brute Force Detection
	+ two main scenarios:
		* Guess or Brute Force a Valid Session ID => launch multiple sequential requests against the target using different session IDs from a single (or set of) IP addresses
			- CM => set the session ID on the attacker end and try to "guess" that a session ID exists
		* Analyze Predictability of the Session ID => launch multiple sequential requests from a single (or set of) IP addresses against the target web application to gather new valid session IDs
			* CM => user sends multiple legitimate login requests to gather a list of session IDs to collect many session IDs for analysis
	* To counter, the system must detect both scenarios based on the number of attempts to gather (or use) different session IDs and then alert / block the offending IP address(es)
- Logging Sessions Life Cycle
	+ log information regarding the full life cycle of sessions. Recommended session related events to record:
		* creation of session ID
		* renewal of session ID
		* destruction of session ID
		* as well as details about usage of session ID within login / logout operations
		* privelege level changes within session
		* timeout expieration
		* invalid session activities
		* critical business operations during the session
	+ log details might include the following:
		* timestamp
		* source IP address
		* web target resource requested
		* HTTP headers (including User-Agent and Referer)
		* GET and POST parameters
		* error codes and messages
		* username (or userID)
		* session ID(cookies, URL, GET, POST)
- Simultaneous Session Logons
	+ do you want to allow multiple simultaneous logons from the same user from different client IP addresses?
	+ 












