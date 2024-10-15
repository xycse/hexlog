#include <stdio.h>
#include <assert.h>
/* string maps for enums */

typedef void *(*data_cb)(void *data);

enum hexlog_name
{
  HN_CREATE,
	HN_READ,
	HN_UPDATE,
	HN_DELETE
};

enum hexlog_status
{
  HS_SUCCESS,
	HS_FAILURE,
	HS_ERROR,
};

struct hexlog
{
  enum hexlog_name 		hn;
	void 								*data;
	enum hexlog_status 	hs;
	data_cb 						dcb;
};

void populate_hexlog_instance(struct hexlog *hxlog, enum hexlog_name hn,
								void *data, enum hexlog_status hs, data_cb dcb)
{
  assert(hxlog != NULL);
	hxlog->hn 	= hn;
	hxlog->data = data;
	hxlog->hs 	= hs;
	hxlog->dcb 	= dcb;
	return;
}

void *hexlog_data_cb(void *data)
{
  return NULL;
}

int main(void)
{
  struct hexlog hxlog;
	const char *str = "hello world!";
	populate_hexlog_instance(&hxlog, HN_CREATE, (void *)str, HS_SUCCESS, hexlog_data_cb);
	return 0;
}
