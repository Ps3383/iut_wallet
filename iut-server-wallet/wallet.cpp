#include "wallet.h"
#include "HashArray.h"

#include <unordered_set>
#include <random>
#include <array>
#include <string>
#include <vector>

std::unordered_set<std::array<std::string, 6>> Wallet::usedWords;

Wallet::Wallet(std::string _email) : USDT(0.0f), email(_email), word1(""), word2(""), word3(""), word4(""), word5(""), word6("") {
    auto words = generateUniqueWords();
    const_cast<std::string&>(word1) = words[0];
    const_cast<std::string&>(word2) = words[1];
    const_cast<std::string&>(word3) = words[2];
    const_cast<std::string&>(word4) = words[3];
    const_cast<std::string&>(word5) = words[4];
    const_cast<std::string&>(word6) = words[5];
}
Wallet::Wallet(){}

// Wallet::Wallet() : USDT(0.0f), word1(""), word2(""), word3(""), word4(""), word5(""), word6("") {
//     auto words = generateUniqueWords();
//     const_cast<std::string&>(word1) = words[0];
//     const_cast<std::string&>(word2) = words[1];
//     const_cast<std::string&>(word3) = words[2];
//     const_cast<std::string&>(word4) = words[3];
//     const_cast<std::string&>(word5) = words[4];
//     const_cast<std::string&>(word6) = words[5];
// }
std::array<std::string, 6> Wallet::generateUniqueWords() const {
    static const std::vector<std::string> wordList = {
        "apple", "banana", "cherry", "date", "elderberry", "fig",
        "grape", "honeydew", "kiwi", "lemon", "mango", "nectarine",
        "orange", "papaya", "quince", "raspberry", "strawberry", "tangerine",
        "umbrella", "victory", "watermelon", "xylophone", "yellow", "zebra",
        "adventure", "beauty", "charm", "destiny", "elegance", "freedom",
        "glory", "harmony", "inspire", "joy", "knowledge", "liberty",
        "magic", "nature", "optimism", "peace", "quest", "radiance",
        "serenity", "tranquility", "unity", "valor", "wisdom", "zenith",
        "bravery", "compassion", "dignity", "enthusiasm", "faith", "gratitude",
        "hope", "integrity", "justice", "kindness", "loyalty", "motivation",
        "nobility", "opportunity", "patience", "quality", "respect", "strength",
        "trust", "understanding", "vision", "wonder", "youth", "zeal",
        "achievement", "balance", "creativity", "determination", "effort",
        "focus", "growth", "honesty", "imagination", "journey", "knowledge",
        "leadership", "mindfulness", "nurture", "open", "passion", "quality",
        "resilience", "success", "transformation", "unity", "victory", "wisdom",
        "xenial", "yearn", "zest"
    };

    static std::mt19937 rng(std::random_device{}());
    std::array<std::string, 6> words;
    do {
        for (auto& word : words) {
            word = wordList[rng() % wordList.size()];
        }
    } while (usedWords.find(words) != usedWords.end());

    usedWords.insert(words);
    return words;
}
// std::array<std::string, 6> Wallet::generateUniqueWords() const {
//     static const std::vector<std::string> wordList = {
//         "apple", "banana", "cherry", "date", "elderberry", "fig",
//         "grape", "honeydew", "kiwi", "lemon", "mango", "nectarine",
//         "orange", "papaya", "quince", "raspberry", "strawberry", "tangerine",
//         "umbrella", "victory", "watermelon", "xylophone", "yellow", "zebra",
//         "adventure", "beauty", "charm", "destiny", "elegance", "freedom",
//         "glory", "harmony", "inspire", "joy", "knowledge", "liberty",
//         "magic", "nature", "optimism", "peace", "quest", "radiance",
//         "serenity", "tranquility", "unity", "valor", "wisdom", "zenith",
//         "bravery", "compassion", "dignity", "enthusiasm", "faith", "gratitude",
//         "hope", "integrity", "justice", "kindness", "loyalty", "motivation",
//         "nobility", "opportunity", "patience", "quality", "respect", "strength",
//         "trust", "understanding", "vision", "wonder", "youth", "zeal",
//         "achievement", "balance", "creativity", "determination", "effort",
//         "focus", "growth", "honesty", "imagination", "journey", "knowledge",
//         "leadership", "mindfulness", "nurture", "open", "passion", "quality",
//         "resilience", "success", "transformation", "unity", "victory", "wisdom",
//         "xenial", "yearn", "zest"
//     };

//     static std::mt19937 rng(std::random_device{}());
//     std::array<std::string, 6> words;
//     do {
//         for (auto& word : words) {
//             word = wordList[rng() % wordList.size()];
//         }
//     } while (usedWords.find(words) != usedWords.end());

//     usedWords.insert(words);
//     return words;
// }
