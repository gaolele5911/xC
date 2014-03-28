#include "../../../xdebug.h"
#include "../../../xpointer.h"
#include "../../../xfile.h"
#include "../../../xmemory.h"
#include "../../include/sys_xtapi.h"
#include<QtGlobal>

#define KTirosLocalMobileIdLen 128

const xchar_t * sys_tapigetmobileid(xsys_tapi_t* ptapi)
{
    QString * pQString = new QString;
    static xchar_t id[KTirosLocalMobileIdLen] = {'\0'};
    if (id[0] != '\0')
    {
        return id;
    }
    else
    {
        xbool_t needCallAPI = true;
        const xchar_t * fileName = "fs0:/config/api/mobileid";
        xbool_t fileExist = xfile_exist(fileName);
        if (fileExist)
        {
            xfile_t * fileHandler = xfile_open("fs0:/config/api/mobileid", OFM_READ);
            if (fileHandler != NULL)
            {
                xuint32_t size =  xfile_read(fileHandler,
                                          (void*)id,
                                          KTirosLocalMobileIdLen);
                if (size != 0)
                {
                    id[size] = '\0';
                    needCallAPI = false;
                }
                xfile_close(fileHandler);
                fileHandler = NULL;
            }
        }
        if (needCallAPI)
        {
            const xchar_t * temp = "123456789012345";
            if (temp != NULL)
            {
                xuint32_t size = pQString->strlen(temp);
                memcpy(id, temp, size + 1);
                xfile_t * fileHandler = xfile_open("fs0:/config/api/mobileid",
                                             OFM_CREATE);
                if (fileHandler != NULL)
                {
                    xuint32_t realSize = xfile_write(fileHandler, temp, size);
                    xfile_close(fileHandler);
                    fileHandler = NULL;
                    if (size != realSize)
                    {
                        xfile_remove("fs0:/config/api/mobileid");
                    }
                }
            }
        }
    }

    return id;
}
