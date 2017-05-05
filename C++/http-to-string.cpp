/* MIT License
 * 
 * Copyright (c) 2017 Sven Kortekaas
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 *  HTTP to string source file
 *
 *  http-to-string.cpp
 *
 *  @license    MIT License
 *  @author     Sven Kortekaas
 *  @copyright  Sven Kortekaas
 */

#include "http-to-string.hpp"

HTTPToString::HTTPToString()
{
    // No implemantation
}

HTTPToString::~HTTPToString()
{
    // No implemantation
}

std::string HTTPToString::httpCode(uint16_t httpCode)
{
    switch(httpCode)
    {
        case 100:
            return "Continue";
        case 101:
            return "Switching Protocols";
        case 102:
            return "Processing";
#ifdef UNOFFICIAL_HTTP_CODES
        case 103:
            return "Checkpoint / Early Hints";
#endif /* UNOFFICIAL_HTTP_CODES */
        case 200:
            return "OK";
        case 201:
            return "Created";
        case 202:
            return "Accepted";
        case 203:
            return "Non-Authoritative Information";
        case 204:
            return "No Content";
        case 205:
            return "Reset Content";
        case 206:
            return "Partial Content";
        case 207:
            return "Multi-Status";
        case 208:
            return "Already Reported";
        case 226:
            return "IM Used";
        case 300:
            return "Multiple Choices";
        case 301:
            return "Moved Permanently";
        case 302:
            return "Found";
        case 303:
            return "See Other";
        case 304:
            return "Not Modified";
        case 305:
            return "Use Proxy";
        case 306:
            return "Switch Proxy";
        case 307:
            return "Temporary Redirect";
        case 308:
            return "Permanent Redirect";
        case 400:
            return "Bad Request";
        case 401:
            return "Unauthorized";
        case 402:
            return "Payment Required";
        case 403:
            return "Forbidden";
        case 404:
            return "Not Found";
        case 405:
            return "Method Not Allowed";
        case 406:
            return "Not Acceptable";
        case 407:
            return "Proxy Authentication Required";
        case 408:
            return "Request Timeout";
        case 409:
            return "Conflict";
        case 410:
            return "Gone";
        case 411:
            return "Length Required";
        case 412:
            return "Precondition Failed";
        case 413:
            return "Payload Too Large";
        case 414:
            return "URI Too Long";
        case 415:
            return "Unsupported Media Type";
        case 416:
            return "Range Not Satisfiable";
        case 417:
            return "Expectation Failed";
        case 418:
            return "I'm a teapot";
#ifdef UNOFFICIAL_HTTP_CODES
        case 420:
            return "Method Failure (Spring Framework) / Enhance Your Calm (Twitter)";
#endif /* UNOFFICIAL_HTTP_CODES */
        case 421:
            return "Misdirected Request";
        case 422:
            return "Unprocessable Entity";
        case 423:
            return "Locked";
        case 424:
            return "Failed Dependency";
        case 426:
            return "Upgrade Required";
        case 428:
            return "Precondition Required";
        case 429:
            return "Too Many Requests";
        case 431:
            return "Request Header Fields Too Large";
#ifdef UNOFFICIAL_HTTP_CODES
        case 420:
            return "Blocked by Windows Parental Controls (Microsoft)";
        case 440:
            return "Login Time-out";
        case 444:
            return "No response";
        case 449:
            return "Retry With";
#endif /* UNOFFICIAL_HTTP_CODES */
        case 450:
            return "Blocked by Windows Parental Controls";
        case 451:
            return "Unavailable For Legal Reasons"
#ifdef UNOFFICIAL_HTTP_CODES            
            + " / Redirect"
#endif /* UNOFFICIAL_HTTP_CODES */
            ;
#ifdef UNOFFICIAL_HTTP_CODES
        case 495:
            return "SSL Certificate Error";
        case 496:
            return "SSL Certificate Required";
        case 497:
            return "HTTP Request Sent to HTTPS Port";
        case 498:
            return "Invalid Token (Esri)";
        case 499:
            return "Token Required (Esri) / Client Closed Request";
#endif /* UNOFFICIAL_HTTP_CODES */
        case 500:
            return "Internal Server Error";
        case 501:
            return "Not Implemented";
        case 502:
            return "Bad Gateway";
        case 503:
            return "Service Unavailable";
        case 504:
            return "Gateway Time-out";
        case 505:
            return "HTTP Version Not Supported";
        case 506:
            return "Variant Also Negotiaties";
        case 507:
            return "Insufficient Storage";
        case 508:
            return "Loop Detected";
#ifdef UNOFFICIAL_HTTP_CODES
        case 509:
            return "Bandwidth Limit Exceeded (Apache Web Server/cPanel)";
#endif /* UNOFFICIAL_HTTP_CODES */
        case 510:
            return "Not Extended";
        case 511:
            return "Network Authentication Required";
#ifdef UNOFFICIAL_HTTP_CODES
        case 520:
            return "Uknown Error";
        case 521:
            return "Web Server Is Down";
        case 522:
            return "Connection Timed Out";
        case 523:
            return "Origin Is Unreachable";
        case 524:
            return "A Timeout Occurred";
        case 525:
            return "SSL Handshake Failed";
        case 526:
            return "Invalid SSL Certificate";
        case 527:
            return "Railgun Error";
        case 530:
            return "Site is frozen";
        case 598:
            return "(Informal convention) Network read timeout error";
        case 599:
            return "(Informal convention) Network connect timeout error";
#endif /* UNOFFICIAL_HTTP_CODES */
        default:
            return "Invalid HTTP code.";
    }
}

std::string HTTPToString::httpCodeFull(uint16_t httpCode)
{
    switch(httpCode)
    {
        case 100:
            return HTTPToString::httpCode(httpCode) + ": The server has received the request headers and the client should proceed to send the request body (in the case of a request for which a body needs to be sent; for example, a POST request). Sending a large request body to a server after a request has been rejected for inappropriate headers would be inefficient. To have a server check the request's headers, a client must send Expect: 100-continue as a header in its initial request and receive a 100 Continue status code in response before sending the body. The response 417 Expectation Failed indicates the request should not be continued.";
        case 101:
            return HTTPToString::httpCode(httpCode) + ": The requester has asked the server to switch protocols and the server has agreed to do so.";
        case 102:
            return HTTPToString::httpCode(httpCode) + ": A WebDAV request may contain many sub-requests involving file operations, requiring a long time to complete the request. This code indicates that the server has received and is processing the request, but no response is available yet. This prevents the client from timing out and assuming the request was lost.";
#ifdef UNOFFICIAL_HTTP_CODES
        case 103:
            return HTTPToString::httpCode(httpCode) + ": Used in the resumable requests proposal to resume aborted PUT or POST requests.";
#endif /* UNOFFICIAL_HTTP_CODES */
        case 200:
            return HTTPToString::httpCode(httpCode) + ": Standard response for successful HTTP requests. The actual response will depend on the request method used. In a GET request, the response will contain an entity corresponding to the requested resource. In a POST request, the response will contain an entity describing or containing the result of the action.";
        case 201:
            return HTTPToString::httpCode(httpCode) + ": The request has been fulfilled, resulting in the creation of a new resource.";
        case 202:
            return HTTPToString::httpCode(httpCode) + ": The request has been accepted for processing, but the processing has not been completed. The request might or might not be eventually acted upon, and may be disallowed when processing occurs.";
        case 203:
            return HTTPToString::httpCode(httpCode) + ": The server is a transforming proxy (e.g. a Web accelerator) that received a 200 OK from its origin, but is returning a modified version of the origin's response.";
        case 204:
            return HTTPToString::httpCode(httpCode) + ": The server successfully processed the request and is not returning any content.";
        case 205:
            return HTTPToString::httpCode(httpCode) + ": The server successfully processed the request, but is not returning any content. Unlike a 204 response, this response requires that the requester reset the document view.";
        case 206:
            return HTTPToString::httpCode(httpCode) + ": The server is delivering only part of the resource (byte serving) due to a range header sent by the client. The range header is used by HTTP clients to enable resuming of interrupted downloads, or split a download into multiple simultaneous streams.";
        case 207:
            return HTTPToString::httpCode(httpCode) + ": The message body that follows is an XML message and can contain a number of separate response codes, depending on how many sub-requests were made.";
        case 208:
            return HTTPToString::httpCode(httpCode) + ": The members of a DAV binding have already been enumerated in a preceding part of the (multistatus) response, and are not being included again.";
        case 226:
            return HTTPToString::httpCode(httpCode) + ": The server has fulfilled a request for the resource, and the response is a representation of the result of one or more instance-manipulations applied to the current instance.";
        case 300:
            return HTTPToString::httpCode(httpCode) + ": Indicates multiple options for the resource from which the client may choose (via agent-driven content negotiation). For example, this code could be used to present multiple video format options, to list files with different filename extensions, or to suggest word-sense disambiguation.";
        case 301:
            return HTTPToString::httpCode(httpCode) + ": This and all future requests should be directed to the given URI.";
        case 302:
            return HTTPToString::httpCode(httpCode) + ": This is an example of industry practice contradicting the standard. The HTTP/1.0 specification (RFC 1945) required the client to perform a temporary redirect (the original describing phrase was \"Moved Temporarily\"), but popular browsers implemented 302 with the functionality of a 303 See Other. Therefore, HTTP/1.1 added status codes 303 and 307 to distinguish between the two behaviours. However, some Web applications and frameworks use the 302 status code as if it were the 303.";
        case 303:
            return HTTPToString::httpCode(httpCode) + ": The response to the request can be found under another URI using a GET method. When received in response to a POST (or PUT/DELETE), the client should presume that the server has received the data and should issue a redirect with a separate GET message.";
        case 304:
            return HTTPToString::httpCode(httpCode) + ": Indicates that the resource has not been modified since the version specified by the request headers If-Modified-Since or If-None-Match. In such case, there is no need to retransmit the resource since the client still has a previously-downloaded copy.";
        case 305:
            return HTTPToString::httpCode(httpCode) + ": The requested resource is available only through a proxy, the address for which is provided in the response. Many HTTP clients (such as Mozilla and Internet Explorer) do not correctly handle responses with this status code, primarily for security reasons.";
        case 306:
            return HTTPToString::httpCode(httpCode) + ": No longer used. Originally meant \"Subsequent requests should use the specified proxy.\"";
        case 307:
            return HTTPToString::httpCode(httpCode) + ": In this case, the request should be repeated with another URI; however, future requests should still use the original URI. In contrast to how 302 was historically implemented, the request method is not allowed to be changed when reissuing the original request. For example, a POST request should be repeated using another POST request.";
        case 308:
            return HTTPToString::httpCode(httpCode) + ": The request and all future requests should be repeated using another URI. 307 and 308 parallel the behaviors of 302 and 301, but do not allow the HTTP method to change. So, for example, submitting a form to a permanently redirected resource may continue smoothly.";
        case 400:
            return HTTPToString::httpCode(httpCode) + ": The server cannot or will not process the request due to an apparent client error (e.g., malformed request syntax, too large size, invalid request message framing, or deceptive request routing).";
        case 401:
            return HTTPToString::httpCode(httpCode) + ": Similar to 403 Forbidden, but specifically for use when authentication is required and has failed or has not yet been provided. The response must include a WWW-Authenticate header field containing a challenge applicable to the requested resource. See Basic access authentication and Digest access authentication. 401 semantically means \"unauthenticated\", i.e. the user does not have the necessary credentials.";
        case 402:
            return HTTPToString::httpCode(httpCode) + ": Reserved for future use. The original intention was that this code might be used as part of some form of digital cash or micropayment scheme, but that has not happened, and this code is not usually used. Google Developers API uses this status if a particular developer has exceeded the daily limit on requests.";
        case 403:
            return HTTPToString::httpCode(httpCode) + ": The request was valid, but the server is refusing action. The user might not have the necessary permissions for a resource.";
        case 404:
            return HTTPToString::httpCode(httpCode) + ": The requested resource could not be found but may be available in the future. Subsequent requests by the client are permissible.";
        case 405:
            return HTTPToString::httpCode(httpCode) + ": A request method is not supported for the requested resource; for example, a GET request on a form that requires data to be presented via POST, or a PUT request on a read-only resource.";
        case 406:
            return HTTPToString::httpCode(httpCode) + ": The requested resource is capable of generating only content not acceptable according to the Accept headers sent in the request.";
        case 407:
            return HTTPToString::httpCode(httpCode) + ": The client must first authenticate itself with the proxy.";
        case 408:
            return HTTPToString::httpCode(httpCode) + ": The server timed out waiting for the request. According to HTTP specifications: \"The client did not produce a request within the time that the server was prepared to wait. The client MAY repeat the request without modifications at any later time.\"";
        case 409:
            return HTTPToString::httpCode(httpCode) + ": Indicates that the request could not be processed because of conflict in the request, such as an edit conflict between multiple simultaneous updates.";
        case 410:
            return HTTPToString::httpCode(httpCode) + ": Indicates that the resource requested is no longer available and will not be available again. This should be used when a resource has been intentionally removed and the resource should be purged. Upon receiving a 410 status code, the client should not request the resource in the future. Clients such as search engines should remove the resource from their indices. Most use cases do not require clients and search engines to purge the resource, and a \"404 Not Found\" may be used instead.";
        case 411:
            return HTTPToString::httpCode(httpCode) + ": The request did not specify the length of its content, which is required by the requested resource.";
        case 412:
            return HTTPToString::httpCode(httpCode) + ": The server does not meet one of the preconditions that the requester put on the request.";
        case 413:
            return HTTPToString::httpCode(httpCode) + ": The request is larger than the server is willing or able to process. Previously called \"Request Entity Too Large\".";
        case 414:
            return HTTPToString::httpCode(httpCode) + ": The URI provided was too long for the server to process. Often the result of too much data being encoded as a query-string of a GET request, in which case it should be converted to a POST request. Called \"Request-URI Too Long\" previously.";
        case 415:
            return HTTPToString::httpCode(httpCode) + ": The request entity has a media type which the server or resource does not support. For example, the client uploads an image as image/svg+xml, but the server requires that images use a different format.";
        case 416:
            return HTTPToString::httpCode(httpCode) + ": The client has asked for a portion of the file (byte serving), but the server cannot supply that portion. For example, if the client asked for a part of the file that lies beyond the end of the file. Called \"Requested Range Not Satisfiable\" previously.";
        case 417:
            return HTTPToString::httpCode(httpCode) + ": The server cannot meet the requirements of the Expect request-header field.";
        case 418:
            return HTTPToString::httpCode(httpCode) + ": This code was defined in 1998 as one of the traditional IETF April Fools' jokes, in RFC 2324, Hyper Text Coffee Pot Control Protocol, and is not expected to be implemented by actual HTTP servers. The RFC specifies this code should be returned by teapots requested to brew coffee. This HTTP status is used as an Easter egg in some websites, including Google.com.";
#ifdef UNOFFICIAL_HTTP_CODES
        case 420:
            return HTTPToString::httpCode(httpCode) + ": (Spring Framework)A deprecated response used by the Spring Framework when a method has failed. (Twitter)Returned by version 1 of the Twitter Search and Trends API when the client is being rate limited; versions 1.1 and later use the 429 Too Many Requests response code instead.";
#endif /* UNOFFICIAL_HTTP_CODES */
        case 421:
            return HTTPToString::httpCode(httpCode) + ": The request was directed at a server that is not able to produce a response (for example because a connection reuse).";
        case 422:
            return HTTPToString::httpCode(httpCode) + ": The request was well-formed but was unable to be followed due to semantic errors.";
        case 423:
            return HTTPToString::httpCode(httpCode) + ": The resource that is being accessed is locked.";
        case 424:
            return HTTPToString::httpCode(httpCode) + ": The request failed due to failure of a previous request (e.g., a PROPPATCH).";
        case 426:
            return HTTPToString::httpCode(httpCode) + ": The client should switch to a different protocol such as TLS/1.0, given in the Upgrade header field.";
        case 428:
            return HTTPToString::httpCode(httpCode) + ": The origin server requires the request to be conditional. Intended to prevent \"the 'lost update' problem, where a client GETs a resource's state, modifies it, and PUTs it back to the server, when meanwhile a third party has modified the state on the server, leading to a conflict.\"";
        case 429:
            return HTTPToString::httpCode(httpCode) + ": The user has sent too many requests in a given amount of time. Intended for use with rate-limiting schemes.";
        case 431:
            return HTTPToString::httpCode(httpCode) + ": The server is unwilling to process the request because either an individual header field, or all the header fields collectively, are too large.";
#ifdef UNOFFICIAL_HTTP_CODES
        case 440:
            return HTTPToString::httpCode(httpCode) + ": The client's session has expired and must log in again.";
        case 444:
            return HTTPToString::httpCode(httpCode) + ": Used to indicate that the server has returned no information to the client and closed the connection.";
        case 449:
            return HTTPToString::httpCode(httpCode) + ": The server cannot honour the request because the user has not provided the required information.";
        case 450:
            return HTTPToString::httpCode(httpCode) + ": The Microsoft extension code indicated when Windows Parental Controls are turned on and are blocking access to the given webpage.";
#endif /* UNOFFICIAL_HTTP_CODES */
        case 451:
            return HTTPToString::httpCode(httpCode) + ": A server operator has received a legal demand to deny access to a resource or to a set of resources that includes the requested resource. The code 451 was chosen as a reference to the novel Fahrenheit 451."
#ifdef UNOFFICIAL_HTTP_CODES            
            + " / Used in Exchange ActiveSync when either a more efficient server is available or the server cannot access the users' mailbox. The client is expected to re-run the HTTP AutoDiscover operation to find a more appropriate server."
#endif /* UNOFFICIAL_HTTP_CODES */
            ;
#ifdef UNOFFICIAL_HTTP_CODES
        case 495:
            return HTTPToString::httpCode(httpCode) + ": An expansion of the 400 Bad Request response code, used when the client has provided an invalid client certificate.";
        case 496:
            return HTTPToString::httpCode(httpCode) + ": An expansion of the 400 Bad Request response code, used when a client certificate is required but not provided.";
        case 497:
            return HTTPToString::httpCode(httpCode) + ": An expansion of the 400 Bad Request response code, used when the client has made a HTTP request to a port listening for HTTPS requests.";
        case 498:
            return HTTPToString::httpCode(httpCode) + ": Returned by ArcGIS for Server. Code 498 indicates an expired or otherwise invalid token.";
        case 499:
            return HTTPToString::httpCode(httpCode) + ": Returned by ArcGIS for Server. Code 499 indicates that a token is required but was not submitted. / Used when the client has closed the request before the server could send a response.";
#endif /* UNOFFICIAL_HTTP_CODES */
        case 500:
            return HTTPToString::httpCode(httpCode) + ": A generic error message, given when an unexpected condition was encountered and no more specific message is suitable.";
        case 501:
            return HTTPToString::httpCode(httpCode) + ": The server either does not recognize the request method, or it lacks the ability to fulfill the request. Usually this implies future availability (e.g., a new feature of a web-service API).";
        case 502:
            return HTTPToString::httpCode(httpCode) + ": The server was acting as a gateway or proxy and received an invalid response from the upstream server.";
        case 503:
            return HTTPToString::httpCode(httpCode) + ": The server is currently unavailable (because it is overloaded or down for maintenance). Generally, this is a temporary state.";
        case 504:
            return HTTPToString::httpCode(httpCode) + ": The server was acting as a gateway or proxy and did not receive a timely response from the upstream server.";
        case 505:
            return HTTPToString::httpCode(httpCode) + ": The server does not support the HTTP protocol version used in the request.";
        case 506:
            return HTTPToString::httpCode(httpCode) + ": Transparent content negotiation for the request results in a circular reference.";
        case 507:
            return HTTPToString::httpCode(httpCode) + ": The server is unable to store the representation needed to complete the request.";
        case 508:
            return HTTPToString::httpCode(httpCode) + ": The server detected an infinite loop while processing the request (sent in lieu of 208 Already Reported).";
#ifdef UNOFFICIAL_HTTP_CODES
        case 509:
            return HTTPToString::httpCode(httpCode) + ": The server has exceeded the bandwidth specified by the server administrator; this is often used by shared hosting providers to limit the bandwidth of customers.";
#endif /* UNOFFICIAL_HTTP_CODES */
        case 510:
            return HTTPToString::httpCode(httpCode) + ": Further extensions to the request are required for the server to fulfill it.";
        case 511:
            return HTTPToString::httpCode(httpCode) + ": The client needs to authenticate to gain network access. Intended for use by intercepting proxies used to control access to the network (e.g., \"captive portals\" used to require agreement to Terms of Service before granting full Internet access via a Wi-Fi hotspot).";
#ifdef UNOFFICIAL_HTTP_CODES
        case 520:
            return HTTPToString::httpCode(httpCode) + ": The 520 error is used as a \"catch-all response for when the origin server returns something unexpected\", listing connection resets, large headers, and empty or invalid responses as common triggers.";
        case 521:
            return HTTPToString::httpCode(httpCode) + ": The origin server has refused the connection from Cloudflare.";
        case 522:
            return HTTPToString::httpCode(httpCode) + ": Cloudflare could not negotiate a TCP handshake with the origin server.";
        case 523:
            return HTTPToString::httpCode(httpCode) + ": Cloudflare could not reach the origin server; for example, if the DNS records for the origin server are incorrect.";
        case 524:
            return HTTPToString::httpCode(httpCode) + ": Cloudflare was able to complete a TCP connection to the origin server, but did not receive a timely HTTP response.";
        case 525:
            return HTTPToString::httpCode(httpCode) + ": Cloudflare could not negotiate a SSL/TLS handshake with the origin server.";
        case 526:
            return HTTPToString::httpCode(httpCode) + ": Cloudflare could not validate the SSL/TLS certificate that the origin server presented.";
        case 527:
            return HTTPToString::httpCode(httpCode) + ": Error 527 indicates that the requests timeout or failed after the WAN connection has been established.";
        case 530:
            return HTTPToString::httpCode(httpCode) + ": Used by the Pantheon web platform to indicate a site that has been frozen due to inactivity.";
        case 598:
            return HTTPToString::httpCode(httpCode) + ": Used by some HTTP proxies to signal a network read timeout behind the proxy to a client in front of the proxy.";
        case 599:
            return HTTPToString::httpCode(httpCode) + ": Used to indicate when the connection to the network times out.";
#endif /* UNOFFICIAL_HTTP_CODES */
        default:
            return "Invalid HTTP code.";
    }
}
