#ifndef CHAIN_H
#define CHAIN_H

#include <iostream>
#include <string>

using namespace std;

enum class RequestType {
	REG_HANDER1,
    REG_HANDER2,
	REG_HANDER3,
};

class Request
{
public:
	Request(const string &desc, RequestType type): description(desc), reqType(type) {}
	RequestType getReqType() const { return reqType; }
	const string & getDescription() const { return description; }

private:
	string description;
	RequestType reqType;
};

class ChainHandler
{
private:
	ChainHandler *nextChain;
	void sentReuqestToNextHandler(const Request &req)
	{
		if (nextChain != nullptr)
			nextChain->handle(req);
	}
protected:
	virtual bool canHandleRequest(const Request &req) = 0;
	virtual void processRequest(const Request &req) = 0;

public:
	ChainHandler()
	{
		nextChain = nullptr;
	}
	void setNextChain(ChainHandler *next)
	{
		nextChain = next;
	}

	void handle(const Request &req)
	{
		if (canHandleRequest(req))
			processRequest(req);
		else
			sentReuqestToNextHandler(req);
	}
};

class Handler1 : public ChainHandler
{
protected:
	bool canHandleRequest(const Request &req) override
	{
		return req.getReqType() == RequestType::REG_HANDER1;
	}

	void processRequest(const Request &req) override
	{
		cout << "Handler1 is handle request: " << req.getDescription() << endl;
	}

};

class Handler2 : public ChainHandler
{
protected:
	bool canHandleRequest(const Request &req) override
	{
		return req.getReqType() == RequestType::REG_HANDER2;
	}

	void processRequest(const Request &req) override
	{
		cout << "Handler2 is handle request: " << req.getDescription() << endl;
	}

};

class Handler3 : public ChainHandler
{
protected:
	bool canHandleRequest(const Request &req) override
	{
		return req.getReqType() == RequestType::REG_HANDER3;
	}

	void processRequest(const Request &req) override
	{
		cout << "Handler3 is handle request: " << req.getDescription() << endl;
	}

};


#endif // CHAIN_H
