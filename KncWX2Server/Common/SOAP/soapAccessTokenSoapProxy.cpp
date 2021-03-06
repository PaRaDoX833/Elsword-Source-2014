/* soapAccessTokenSoapProxy.cpp
   Generated by gSOAP 2.8.15 from nx_soap.h

Copyright(C) 2000-2013, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under ONE of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#include "soapAccessTokenSoapProxy.h"

AccessTokenSoapProxy::AccessTokenSoapProxy()
{	AccessTokenSoapProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

AccessTokenSoapProxy::AccessTokenSoapProxy(const struct soap &_soap) : soap(_soap)
{ }

AccessTokenSoapProxy::AccessTokenSoapProxy(const char *url)
{	AccessTokenSoapProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
	soap_endpoint = url;
}

AccessTokenSoapProxy::AccessTokenSoapProxy(soap_mode iomode)
{	AccessTokenSoapProxy_init(iomode, iomode);
}

AccessTokenSoapProxy::AccessTokenSoapProxy(const char *url, soap_mode iomode)
{	AccessTokenSoapProxy_init(iomode, iomode);
	soap_endpoint = url;
}

AccessTokenSoapProxy::AccessTokenSoapProxy(soap_mode imode, soap_mode omode)
{	AccessTokenSoapProxy_init(imode, omode);
}

AccessTokenSoapProxy::~AccessTokenSoapProxy()
{ }

void AccessTokenSoapProxy::AccessTokenSoapProxy_init(soap_mode imode, soap_mode omode)
{	soap_imode(this, imode);
	soap_omode(this, omode);
	soap_endpoint = NULL;
	static const struct Namespace namespaces[] =
{
	{"SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL},
	{"SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL},
	{"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
	{"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
	{"ns1", "http://tempuri.org/", NULL, NULL},
	{"ns2", "http://nxgamechanneling.nexon.game.naver.com/external/GetAccessToken", NULL, NULL},
	{NULL, NULL, NULL, NULL}
};
	soap_set_namespaces(this, namespaces);
}

void AccessTokenSoapProxy::destroy()
{	soap_destroy(this);
	soap_end(this);
}

void AccessTokenSoapProxy::reset()
{	destroy();
	soap_done(this);
	soap_init(this);
	AccessTokenSoapProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

void AccessTokenSoapProxy::soap_noheader()
{	this->header = NULL;
}

const SOAP_ENV__Header *AccessTokenSoapProxy::soap_header()
{	return this->header;
}

const SOAP_ENV__Fault *AccessTokenSoapProxy::soap_fault()
{	return this->fault;
}

const char *AccessTokenSoapProxy::soap_fault_string()
{	return *soap_faultstring(this);
}

const char *AccessTokenSoapProxy::soap_fault_detail()
{	return *soap_faultdetail(this);
}

int AccessTokenSoapProxy::soap_close_socket()
{	return soap_closesock(this);
}

int AccessTokenSoapProxy::soap_force_close_socket()
{	return soap_force_closesock(this);
}

void AccessTokenSoapProxy::soap_print_fault(FILE *fd)
{	::soap_print_fault(this, fd);
}

#ifndef WITH_LEAN
#ifndef WITH_COMPAT
void AccessTokenSoapProxy::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this, os);
}
#endif

char *AccessTokenSoapProxy::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this, buf, len);
}
#endif

int AccessTokenSoapProxy::GetGameAccessToken(const char *endpoint, const char *soap_action, _ns2__GetGameAccessToken *ns2__GetGameAccessToken, _ns2__GetGameAccessTokenResponse *ns2__GetGameAccessTokenResponse)
{	struct soap *soap = this;
	struct __ns2__GetGameAccessToken soap_tmp___ns2__GetGameAccessToken;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://nxgamechanneling.nexon.game.naver.com/external/accesstoken.asmx";
	if (soap_action == NULL)
		soap_action = "http://nxgamechanneling.nexon.game.naver.com/external/GetAccessToken/GetGameAccessToken";
	soap->encodingStyle = NULL;
	soap_tmp___ns2__GetGameAccessToken.ns2__GetGameAccessToken = ns2__GetGameAccessToken;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns2__GetGameAccessToken(soap, &soap_tmp___ns2__GetGameAccessToken);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns2__GetGameAccessToken(soap, &soap_tmp___ns2__GetGameAccessToken, "-ns2:GetGameAccessToken", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns2__GetGameAccessToken(soap, &soap_tmp___ns2__GetGameAccessToken, "-ns2:GetGameAccessToken", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns2__GetGameAccessTokenResponse)
		return soap_closesock(soap);
	ns2__GetGameAccessTokenResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns2__GetGameAccessTokenResponse->soap_get(soap, "ns2:GetGameAccessTokenResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int AccessTokenSoapProxy::GetGameAccessToken_(const char *endpoint, const char *soap_action, _ns2__GetGameAccessToken *ns2__GetGameAccessToken, _ns2__GetGameAccessTokenResponse *ns2__GetGameAccessTokenResponse)
{	struct soap *soap = this;
	struct __ns2__GetGameAccessToken_ soap_tmp___ns2__GetGameAccessToken_;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://nxgamechanneling.nexon.game.naver.com/external/accesstoken.asmx";
	if (soap_action == NULL)
		soap_action = "http://nxgamechanneling.nexon.game.naver.com/external/GetAccessToken/GetGameAccessToken";
	soap->encodingStyle = NULL;
	soap_tmp___ns2__GetGameAccessToken_.ns2__GetGameAccessToken = ns2__GetGameAccessToken;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns2__GetGameAccessToken_(soap, &soap_tmp___ns2__GetGameAccessToken_);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns2__GetGameAccessToken_(soap, &soap_tmp___ns2__GetGameAccessToken_, "-ns2:GetGameAccessToken", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns2__GetGameAccessToken_(soap, &soap_tmp___ns2__GetGameAccessToken_, "-ns2:GetGameAccessToken", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns2__GetGameAccessTokenResponse)
		return soap_closesock(soap);
	ns2__GetGameAccessTokenResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns2__GetGameAccessTokenResponse->soap_get(soap, "ns2:GetGameAccessTokenResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}
/* End of client proxy code */
