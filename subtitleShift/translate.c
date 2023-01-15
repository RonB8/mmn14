#include <stdio.h>
#include <strings.h>
#include <curl/curl.h>

CURL *hnd = curl_easy_init();

curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "POST");
curl_easy_setopt(hnd, CURLOPT_URL, "https://google-translate1.p.rapidapi.com/language/translate/v2/detect");

struct curl_slist *headers = NULL;
headers = curl_slist_append(headers, "content-type: application/x-www-form-urlencoded");
headers = curl_slist_append(headers, "Accept-Encoding: application/gzip");
headers = curl_slist_append(headers, "X-RapidAPI-Key: 2a35258771msha2d754a85014d7dp13062fjsnfa9dd0893348");
headers = curl_slist_append(headers, "X-RapidAPI-Host: google-translate1.p.rapidapi.com");
curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);

curl_easy_setopt(hnd, CURLOPT_POSTFIELDS, "q=English%20is%20hard%2C%20but%20detectably%20so");

CURLcode ret = curl_easy_perform(hnd);
