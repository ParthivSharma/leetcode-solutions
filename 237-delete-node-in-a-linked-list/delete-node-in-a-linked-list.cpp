class Solution {
public:
    void deleteNode(ListNode* node) {
        // Copy the value from the next node to the current node
        node->val = node->next->val;
        // Store the next node
        ListNode* temp = node->next;
        // Link the current node to the next of next node
        node->next = node->next->next;
        // Free the memory of the next node
        delete temp;
    }
};
