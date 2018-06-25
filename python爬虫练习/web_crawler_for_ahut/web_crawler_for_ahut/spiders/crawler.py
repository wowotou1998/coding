# -*- coding: utf-8 -*-
import scrapy


class CrawlerSpider(scrapy.Spider):
    name = 'crawler'
    #allowed_domains = ['ahut.com']
    start_urls = ['http://python123.io/ws/demo.html']

    def parse(self, response):
        fname = response.url.split('/t')[-1]
        with open (fname,'wb') as f:
            f.write(response.body)
        self.log('saved file %s.'% fname)

