/*************************************************************************
	> File Name: memory.c
	> Author: likeyi
	> Mail: likeyiyy@sina.com 
	> Created Time: Thu 19 Jun 2014 01:48:13 PM CST
 ************************************************************************/

#include "includes.h"

/*
 * littel duan
 * size is MB uint
 * */
memory_t * init_memory(uint32_t size)
{
    memory_t * m = malloc(sizeof(memory_t));
    exit_if_ptr_is_null(m,"Error: when alloc memory struct");

    m->size = size * MB_SIZE;

    m->memory = malloc(m->size);
    exit_if_ptr_is_null(m->memory,"Error: when alloc memory_t memory");
    memset(m->memory,0,m->size);
    
    return m;
}
memory_t * get_memory(void)
{
    static memory_t * m = NULL;

    if(m != NULL)
    {
        return m;
    }

    m = init_memory(MEMORY_SIZE);

    return m;
}
#define EXIT_IF_ADDR_BIGGER(addr,size) do \
{\
    if(addr > size)\
    {\
        printf("Error: read addr is BIGGER than memory size %u > %u\n",addr,size);\
        exit(-1);\
    }\
}while(0)
void read_memory_8(memory_t * m,uint32_t addr,uint8_t * value)
{
    EXIT_IF_ADDR_BIGGER(addr,m->size);
    *value = m->memory[addr];
}

void write_memory_8(memory_t * m, uint32_t addr,uint8_t  value)
{
    EXIT_IF_ADDR_BIGGER(addr,m->size);
    m->memory[addr] = value;
}


void read_memory_16(memory_t * m, uint32_t addr,uint16_t * value)
{
    EXIT_IF_ADDR_BIGGER(addr,m->size);
    *value = *(uint16_t *)&m->memory[addr];
}

void write_memory_16(memory_t * m, uint32_t addr,uint16_t  value)
{
    EXIT_IF_ADDR_BIGGER(addr,m->size);
    *(uint16_t *)&m->memory[addr] = value;
}



void read_memory_32(memory_t * m, uint32_t addr,uint32_t  * value)
{ 
    EXIT_IF_ADDR_BIGGER(addr,m->size);
    *value = *(uint32_t *)&m->memory[addr];
} 

void write_memory_32(memory_t * m, uint32_t addr,uint32_t  value)
{
    EXIT_IF_ADDR_BIGGER(addr,m->size);
    *(uint32_t *)&m->memory[addr] = value;
}
