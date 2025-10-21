#ifndef LIST
#define LIST

#include <cstdint>
#include <exception>
template<typename T>
class List
{
private:
    class ListItem
    {
        T data;
        ListItem * next;
        ListItem * prev;
        friend class List;
    };
    size_t payloadCount;
    ListItem * sntl;
public:
    List(void)
    {
        payloadCount = 0;
        sntl = new ListItem;
        sntl -> next = sntl;
        sntl -> prev = sntl;
    }
    void pushBack(ListItem& newElem)
    {
        newElem -> next = sntl;
        newElem -> prev = sntl -> prev;
        (sntl -> prev) -> next = newElem;
        sntl -> prev = newElem; 
    }
    void pushStart(ListItem& newItem)
    {
        
    }

};






#endif