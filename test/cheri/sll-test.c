#include <assert.h>
#include <slimguard.h>
#include <sll.h>

int main(void) {
    sll_t *head = NULL;
    uint8_t iter = 100;

    for (uint32_t i = 0; i < iter; i++){
        sll_t *node = (sll_t *)malloc(sizeof(void *));
        node->next = NULL;
        head = add_head(node, head);
    }

    for (uint32_t i = 0; i < iter; i++){
        assert(head->next == next_entry(head));
        remove_head(head);
    }

}
