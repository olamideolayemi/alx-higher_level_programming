#!/usr/bin/python3
def multiple_returns(sentence):
    if not sentence:
        sentence = None
    if sentence:
        sentence_len = len(sentence)
    else:
        sentense_len = 0
    return (sentence_len, sentence if not sentence else sentence[:1])
