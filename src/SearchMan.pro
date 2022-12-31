QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = searcher
TEMPLATE = app


SOURCES += \
    main.cpp \
    widget.cpp \
    crawlerthread.cpp \
    widget_crawlslots.cpp \
    widget_funcs.cpp \
    crawler3.1.cpp \
    widget_initridslots.cpp \
    initridthread.cpp \
    rid2.1.cpp \
    expr.cpp

HEADERS  += \
    cppjieba/DictTrie.hpp \
    cppjieba/FullSegment.hpp \
    cppjieba/HMMModel.hpp \
    cppjieba/HMMSegment.hpp \
    cppjieba/Jieba.hpp \
    cppjieba/KeywordExtractor.hpp \
    cppjieba/MPSegment.hpp \
    cppjieba/MixSegment.hpp \
    cppjieba/PosTagger.hpp \
    cppjieba/PreFilter.hpp \
    cppjieba/QuerySegment.hpp \
    cppjieba/SegmentBase.hpp \
    cppjieba/SegmentTagged.hpp \
    cppjieba/TextRankExtractor.hpp \
    cppjieba/Trie.hpp \
    cppjieba/Unicode.hpp \
    limonp/ArgvContext.hpp \
    limonp/BlockingQueue.hpp \
    limonp/BoundedBlockingQueue.hpp \
    limonp/BoundedQueue.hpp \
    limonp/Closure.hpp \
    limonp/Colors.hpp \
    limonp/Condition.hpp \
    limonp/Config.hpp \
    limonp/FileLock.hpp \
    limonp/ForcePublic.hpp \
    limonp/LocalVector.hpp \
    limonp/Logging.hpp \
    limonp/Md5.hpp \
    limonp/MutexLock.hpp \
    limonp/NonCopyable.hpp \
    limonp/StdExtension.hpp \
    limonp/StringUtil.hpp \
    limonp/Thread.hpp \
    limonp/ThreadPool.hpp \
    widget.h \
    crawlerthread.h \
    rid.h \
    crawler.h \
    initridthread.h \
    mystack.h \
    expr.h
FORMS    += widget.ui

CONFIG += c++11

LIBS += -lws2_32

DEFINES-= UNICODE #for ExecuteShellA's use

RC_FILE = icon.rc #for exe's icon
