from typing import List

class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end_of_word = False

class Trie:
    def __init__(self):
        self.root = TrieNode()
        
    def insert(self, word: str):
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.is_end_of_word = True

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        # Build the Trie
        trie = Trie()
        for word in words:
            trie.insert(word)

        m, n = len(board), len(board[0])
        result = set()
        visited = set()

        def backtrack(x: int, y: int, node: TrieNode, path: str):
            if node.is_end_of_word:
                result.add(path)
                node.is_end_of_word = False  # Avoid duplicate entries
            
            # Directions for moving in the board
            directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
            
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n and (nx, ny) not in visited:
                    next_char = board[nx][ny]
                    if next_char in node.children:
                        visited.add((nx, ny))
                        backtrack(nx, ny, node.children[next_char], path + next_char)
                        visited.remove((nx, ny))

        for i in range(m):
            for j in range(n):
                start_char = board[i][j]
                if start_char in trie.root.children:
                    visited.add((i, j))
                    backtrack(i, j, trie.root.children[start_char], start_char)
                    visited.remove((i, j))

        return list(result)


        
