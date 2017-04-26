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
        case 524:
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
            return HTTPToString::httpCode(httpCode) + ": ";
        case 101:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 102:
            return HTTPToString::httpCode(httpCode) + ": ";
#ifdef UNOFFICIAL_HTTP_CODES
        case 103:
            return HTTPToString::httpCode(httpCode) + ": ";
#endif /* UNOFFICIAL_HTTP_CODES */
        case 200:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 201:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 202:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 203:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 204:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 205:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 206:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 207:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 208:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 226:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 300:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 301:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 302:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 303:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 304:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 305:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 306:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 307:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 308:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 400:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 401:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 402:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 403:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 404:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 405:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 406:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 407:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 408:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 409:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 410:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 411:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 412:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 413:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 414:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 415:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 416:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 417:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 418:
            return HTTPToString::httpCode(httpCode) + ": ";
#ifdef UNOFFICIAL_HTTP_CODES
        case 420:
            return HTTPToString::httpCode(httpCode) + ": ";
#endif /* UNOFFICIAL_HTTP_CODES */
        case 421:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 422:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 423:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 424:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 426:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 428:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 429:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 431:
            return HTTPToString::httpCode(httpCode) + ": ";
#ifdef UNOFFICIAL_HTTP_CODES
        case 420:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 440:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 444:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 449:
            return HTTPToString::httpCode(httpCode) + ": ";
#endif /* UNOFFICIAL_HTTP_CODES */
        case 451:
            return HTTPToString::httpCode(httpCode) + ": "
#ifdef UNOFFICIAL_HTTP_CODES            
            + " / "
#endif /* UNOFFICIAL_HTTP_CODES */
            ;
#ifdef UNOFFICIAL_HTTP_CODES
        case 495:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 496:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 497:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 498:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 499:
            return HTTPToString::httpCode(httpCode) + ": ";
#endif /* UNOFFICIAL_HTTP_CODES */
        case 500:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 501:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 502:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 503:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 504:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 505:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 506:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 507:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 508:
            return HTTPToString::httpCode(httpCode) + ": ";
#ifdef UNOFFICIAL_HTTP_CODES
        case 509:
            return HTTPToString::httpCode(httpCode) + ": ";
#endif /* UNOFFICIAL_HTTP_CODES */
        case 510:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 511:
            return HTTPToString::httpCode(httpCode) + ": ";
#ifdef UNOFFICIAL_HTTP_CODES
        case 520:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 521:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 522:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 523:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 524:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 524:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 526:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 527:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 530:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 598:
            return HTTPToString::httpCode(httpCode) + ": ";
        case 599:
            return HTTPToString::httpCode(httpCode) + ": ";
#endif /* UNOFFICIAL_HTTP_CODES */
        default:
            return "Invalid HTTP code.";
    }
}