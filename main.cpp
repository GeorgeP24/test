#include"include/lc.h"

#include<iostream>
#include<cassert>



#define NAME(n) f##n  
   
int main()  
{  
      
    int NAME(a);  
    int NAME(b);  
      
    NAME(a) = 520;  
    NAME(b) = 111;  
      
    printf("%d\n", NAME(a));  
    printf("%d\n", NAME(b));  
   
    return 0;  

}
// DHA_DBG_GET_PGA_REG_INFO


// DBG_CMD_REG_DATA group_name[] = 

	
// DRV_DEBUG_CMD(DRV_MODULE_ID_DHA_PGA_DEBUG, 
//               DHA_DBG_GET_5315_REG_INFO,
//               4,
//               "get-5315-reg-info",
//               "para[0]board_id,para[1]portid with real board_id,para[2]reg page,para[3]reg addr\n"
//               "reg page:default is 0"),
// DRV_DEBUG_CMD(DRV_MODULE_ID_DHA_PGA_DEBUG, DHA_DBG_XXXX_XXX_INFO,
//                x,
//                "")
// DRV_DEBUG_CMDS_END()