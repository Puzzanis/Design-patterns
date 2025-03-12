#pragma once

#include <map>
#include <string>
#include <iostream>

class VeryHeavyDatabase {
public:
    std::string GetData(const std::string& key) const noexcept {
        return "Very Big Data String: " + key;
    }
};

class CacheProxyDB : VeryHeavyDatabase {
public:
    explicit CacheProxyDB(VeryHeavyDatabase* real_object) : real_db_(real_object) {}
    std::string GetData(const std::string& key) noexcept {
        if (cache_.find(key) == cache_.end()) {
            std::cout << "Get from real object\n";
            cache_[key] = real_db_->GetData(key);
        }
        else {
            std::cout << "Get from cache\n";
        }
        return cache_.at(key);
    }

private:
    std::map<std::string, std::string> cache_;
    VeryHeavyDatabase* real_db_;
};

class TestDB : VeryHeavyDatabase {
public:
    explicit TestDB(VeryHeavyDatabase* real_object) : real_db_(real_object) {}
    std::string GetData(const std::string& key) noexcept {
        return "test_data\n";
    }
private:
    VeryHeavyDatabase* real_db_;
};

class OneShotDB
{
public:
    explicit class OneShotDB(VeryHeavyDatabase* real_object, const int& limit) : real_db_(real_object), limit_(limit) {}
    std::string GetData(const std::string& key) noexcept 
    {
        if (count_ < limit_)
        {
            count_ += 1;
            return real_db_->GetData(key);
        }
        return "error\n";
    }

private:
    int limit_;
    int count_{ 0 };
    VeryHeavyDatabase* real_db_;
};