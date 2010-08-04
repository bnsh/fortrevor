#! /usr/local/bin/perl

use strict;
use LWP;
use POSIX qw(strftime);
use HTTP::Cookies;
use IO::File;

{
	my $i;
	my @t = localtime(time);
	my $timestrdir = strftime("data/%Y/%m/%d",@t);
	my $timestr = strftime("data/%Y/%m/%d/%%s-%H%M%S",@t);

	&magic_mkdir($timestrdir);

	for ($i = 0; $i < scalar(@ARGV); ++$i) {
		&retrieve_quote($ARGV[$i],$timestr);
	}
}

sub retrieve_quote($$) {
	my ($symbol,$timestr) = @_;
	my $ua = new LWP::UserAgent("requests_redirectable" =>  ['GET', 'HEAD', 'POST']);
	my $cookie_jar = new HTTP::Cookies();

	$ua->agent("Mozilla/5.0 (X11; U; Linux i686; en-US; rv:1.3) Gecko/20030312");
	$ua->cookie_jar($cookie_jar);
	my $req = new HTTP::Request("GET" => "http://www.cboe.com/DelayedQuote/QuoteTableDownload.aspx");
	$ua->request($req);

	my $req = new HTTP::Request("POST" => "http://www.cboe.com/DelayedQuote/QuoteTableDownload.aspx");
	$req->content_type("application/x-www-form-urlencoded");

#	my $content = sprintf("__EVENTTARGET=&__EVENTARGUMENT=&__VIEWSTATE=dDwtODc5MTM4MTUwOzs%%2B6wDeQv0gEC342sUPKG%%2B3n6ZStJ8%%3D&ucHeader%%3AucCBOEHeaderLinks%%3AucCBOEHeaderSearch%%3Asearchtext=&txtTicker=%s&cmdSubmit=Download",$symbol);
#	my $content = sprintf("__EVENTTARGET=&__EVENTARGUMENT=&__VIEWSTATE=dDwtODQ5MjIyNjc7Oz5rmegY%%2B4O27l7uWcpGd4iU%%2B1RpAA%%3D%%3D&ucHeader%%3AucCBOEHeaderLinks%%3AucCBOEHeaderSearch%%3Asearchtext=&ucQuoteTableDownloadCtl%%3AtxtTicker=%s&ucQuoteTableDownloadCtl%%3AcmdSubmit=Download",$symbol);
	my $content = sprintf(q{__EVENTTARGET=&__EVENTARGUMENT=&__VIEWSTATE=%%2FwEPDwUKLTc3NTgxOTcwNw9kFgJmD2QWAmYPZBYCAgUPZBYCAgMPZBYEAgUPZBYCAgEPZBYCAgcPZBYIAgEPZBYCAgIPZBYKAggPFgIeBFRleHQFgAI8SUZSQU1FIHNyYz0iaHR0cDovL2FkLmRvdWJsZWNsaWNrLm5ldC9hZGkvcXVvdGUuY2JvZS5kYXJ0L3F1b3RlL3F1b3RldGFibGVkb3dubG9hZDtzej0xMjB4NjA7dGlsZT0yO29yZD0nICsgb3JkICsgJyIgd2lkdGg9IjEyMCIgaGVpZ2h0PSI2MCIgdmFsaWduPSJ0b3AiIGFsaWduPSJjZW50ZXIiIG1hcmdpbndpZHRoPSIwIiBtYXJnaW5oZWlnaHQ9IjAiIGhzcGFjZT0iMCIgdnNwYWNlPSIwIiBmcmFtZWJvcmRlcj0iMCIgc2Nyb2xsaW5nPSJubyI%%2BZAIKDxYCHwAFgwEgIDxBIGhyZWY9Imh0dHA6Ly9hZC5kb3VibGVjbGljay5uZXQvanVtcC9xdW90ZS5jYm9lLmRhcnQvcXVvdGUvcXVvdGV0YWJsZWRvd25sb2FkO3N6PTEyMHg2MDt0aWxlPTI7b3JkPScgKyBvcmQgKyAnIiB0YXJnZXQ9Il9uZXciPmQCDA8WAh8ABa8BICAgIDxJTUcgc3JjPSJodHRwOi8vYWQuZG91YmxlY2xpY2submV0L2FkL3F1b3RlLmNib2UuZGFydC9xdW90ZS9xdW90ZXRhYmxlZG93bmxvYWQ7c3o9MTIweDYwO3RpbGU9MjtvcmQ9JyArIG9yZCArICciIHdpZHRoPSIxMjAiIGhlaWdodD0iNjAiIGJvcmRlcj0iMCIgYWx0PSJBRCI%%2BPC9BPjwvSUZSQU1FPmQCDg8WAh8ABVo8QSBIUkVGPSJodHRwOi8vYWQuZG91YmxlY2xpY2submV0L2p1bXAvcXVvdGUuY2JvZS5kYXJ0Lztzej0xMjB4NjA7dGlsZT0yO29yZD0xMjM0NTY3ODk%%2FIj5kAhAPFgIfAAWJATxJTUcgU1JDPSJodHRwOi8vYWQuZG91YmxlY2xpY2submV0L2FkL3F1b3RlLmNib2UuZGFydC87c3o9MTIweDYwO3RpbGU9MjtvcmQ9MTIzNDU2Nzg5PyIgd2lkdGg9IjEyMCIgaGVpZ2h0PSI2MCIgYm9yZGVyPSIwIiBhbHQ9IkFEIj48L0E%%2BZAIDD2QWAgICD2QWCgIIDxYCHwAFgAI8SUZSQU1FIHNyYz0iaHR0cDovL2FkLmRvdWJsZWNsaWNrLm5ldC9hZGkvcXVvdGUuY2JvZS5kYXJ0L3F1b3RlL3F1b3RldGFibGVkb3dubG9hZDtzej0xMjB4NjA7dGlsZT0zO29yZD0nICsgb3JkICsgJyIgd2lkdGg9IjEyMCIgaGVpZ2h0PSI2MCIgdmFsaWduPSJ0b3AiIGFsaWduPSJjZW50ZXIiIG1hcmdpbndpZHRoPSIwIiBtYXJnaW5oZWlnaHQ9IjAiIGhzcGFjZT0iMCIgdnNwYWNlPSIwIiBmcmFtZWJvcmRlcj0iMCIgc2Nyb2xsaW5nPSJubyI%%2BZAIKDxYCHwAFgwEgIDxBIGhyZWY9Imh0dHA6Ly9hZC5kb3VibGVjbGljay5uZXQvanVtcC9xdW90ZS5jYm9lLmRhcnQvcXVvdGUvcXVvdGV0YWJsZWRvd25sb2FkO3N6PTEyMHg2MDt0aWxlPTM7b3JkPScgKyBvcmQgKyAnIiB0YXJnZXQ9Il9uZXciPmQCDA8WAh8ABa8BICAgIDxJTUcgc3JjPSJodHRwOi8vYWQuZG91YmxlY2xpY2submV0L2FkL3F1b3RlLmNib2UuZGFydC9xdW90ZS9xdW90ZXRhYmxlZG93bmxvYWQ7c3o9MTIweDYwO3RpbGU9MztvcmQ9JyArIG9yZCArICciIHdpZHRoPSIxMjAiIGhlaWdodD0iNjAiIGJvcmRlcj0iMCIgYWx0PSJBRCI%%2BPC9BPjwvSUZSQU1FPmQCDg8WAh8ABVo8QSBIUkVGPSJodHRwOi8vYWQuZG91YmxlY2xpY2submV0L2p1bXAvcXVvdGUuY2JvZS5kYXJ0Lztzej0xMjB4NjA7dGlsZT0zO29yZD0xMjM0NTY3ODk%%2FIj5kAhAPFgIfAAWJATxJTUcgU1JDPSJodHRwOi8vYWQuZG91YmxlY2xpY2submV0L2FkL3F1b3RlLmNib2UuZGFydC87c3o9MTIweDYwO3RpbGU9MztvcmQ9MTIzNDU2Nzg5PyIgd2lkdGg9IjEyMCIgaGVpZ2h0PSI2MCIgYm9yZGVyPSIwIiBhbHQ9IkFEIj48L0E%%2BZAIFD2QWAgICD2QWCgIIDxYCHwAFgAI8SUZSQU1FIHNyYz0iaHR0cDovL2FkLmRvdWJsZWNsaWNrLm5ldC9hZGkvcXVvdGUuY2JvZS5kYXJ0L3F1b3RlL3F1b3RldGFibGVkb3dubG9hZDtzej0xMjB4NjA7dGlsZT00O29yZD0nICsgb3JkICsgJyIgd2lkdGg9IjEyMCIgaGVpZ2h0PSI2MCIgdmFsaWduPSJ0b3AiIGFsaWduPSJjZW50ZXIiIG1hcmdpbndpZHRoPSIwIiBtYXJnaW5oZWlnaHQ9IjAiIGhzcGFjZT0iMCIgdnNwYWNlPSIwIiBmcmFtZWJvcmRlcj0iMCIgc2Nyb2xsaW5nPSJubyI%%2BZAIKDxYCHwAFgwEgIDxBIGhyZWY9Imh0dHA6Ly9hZC5kb3VibGVjbGljay5uZXQvanVtcC9xdW90ZS5jYm9lLmRhcnQvcXVvdGUvcXVvdGV0YWJsZWRvd25sb2FkO3N6PTEyMHg2MDt0aWxlPTQ7b3JkPScgKyBvcmQgKyAnIiB0YXJnZXQ9Il9uZXciPmQCDA8WAh8ABa8BICAgIDxJTUcgc3JjPSJodHRwOi8vYWQuZG91YmxlY2xpY2submV0L2FkL3F1b3RlLmNib2UuZGFydC9xdW90ZS9xdW90ZXRhYmxlZG93bmxvYWQ7c3o9MTIweDYwO3RpbGU9NDtvcmQ9JyArIG9yZCArICciIHdpZHRoPSIxMjAiIGhlaWdodD0iNjAiIGJvcmRlcj0iMCIgYWx0PSJBRCI%%2BPC9BPjwvSUZSQU1FPmQCDg8WAh8ABVo8QSBIUkVGPSJodHRwOi8vYWQuZG91YmxlY2xpY2submV0L2p1bXAvcXVvdGUuY2JvZS5kYXJ0Lztzej0xMjB4NjA7dGlsZT00O29yZD0xMjM0NTY3ODk%%2FIj5kAhAPFgIfAAWJATxJTUcgU1JDPSJodHRwOi8vYWQuZG91YmxlY2xpY2submV0L2FkL3F1b3RlLmNib2UuZGFydC87c3o9MTIweDYwO3RpbGU9NDtvcmQ9MTIzNDU2Nzg5PyIgd2lkdGg9IjEyMCIgaGVpZ2h0PSI2MCIgYm9yZGVyPSIwIiBhbHQ9IkFEIj48L0E%%2BZAIHD2QWAgICD2QWCgIIDxYCHwAFgAI8SUZSQU1FIHNyYz0iaHR0cDovL2FkLmRvdWJsZWNsaWNrLm5ldC9hZGkvcXVvdGUuY2JvZS5kYXJ0L3F1b3RlL3F1b3RldGFibGVkb3dubG9hZDtzej0xMjB4NjA7dGlsZT01O29yZD0nICsgb3JkICsgJyIgd2lkdGg9IjEyMCIgaGVpZ2h0PSI2MCIgdmFsaWduPSJ0b3AiIGFsaWduPSJjZW50ZXIiIG1hcmdpbndpZHRoPSIwIiBtYXJnaW5oZWlnaHQ9IjAiIGhzcGFjZT0iMCIgdnNwYWNlPSIwIiBmcmFtZWJvcmRlcj0iMCIgc2Nyb2xsaW5nPSJubyI%%2BZAIKDxYCHwAFgwEgIDxBIGhyZWY9Imh0dHA6Ly9hZC5kb3VibGVjbGljay5uZXQvanVtcC9xdW90ZS5jYm9lLmRhcnQvcXVvdGUvcXVvdGV0YWJsZWRvd25sb2FkO3N6PTEyMHg2MDt0aWxlPTU7b3JkPScgKyBvcmQgKyAnIiB0YXJnZXQ9Il9uZXciPmQCDA8WAh8ABa8BICAgIDxJTUcgc3JjPSJodHRwOi8vYWQuZG91YmxlY2xpY2submV0L2FkL3F1b3RlLmNib2UuZGFydC9xdW90ZS9xdW90ZXRhYmxlZG93bmxvYWQ7c3o9MTIweDYwO3RpbGU9NTtvcmQ9JyArIG9yZCArICciIHdpZHRoPSIxMjAiIGhlaWdodD0iNjAiIGJvcmRlcj0iMCIgYWx0PSJBRCI%%2BPC9BPjwvSUZSQU1FPmQCDg8WAh8ABVo8QSBIUkVGPSJodHRwOi8vYWQuZG91YmxlY2xpY2submV0L2p1bXAvcXVvdGUuY2JvZS5kYXJ0Lztzej0xMjB4NjA7dGlsZT01O29yZD0xMjM0NTY3ODk%%2FIj5kAhAPFgIfAAWJATxJTUcgU1JDPSJodHRwOi8vYWQuZG91YmxlY2xpY2submV0L2FkL3F1b3RlLmNib2UuZGFydC87c3o9MTIweDYwO3RpbGU9NTtvcmQ9MTIzNDU2Nzg5PyIgd2lkdGg9IjEyMCIgaGVpZ2h0PSI2MCIgYm9yZGVyPSIwIiBhbHQ9IkFEIj48L0E%%2BZAIID2QWAgICD2QWDgIBDw8WAh4HVmlzaWJsZWhkZAICD2QWAgIBDxYCHwAFmgE8SUZSQU1FIHNyYz0iaHR0cDovL2RlbGF5ZWRxdW90ZXMuY2JvZS5jb20vbmV3L2luZGljZXMvaW5kaWNlcy5odG1sIiBoZWlnaHQ9IjMyNSIgd2lkdGg9IjMwMCIgaWQ9IklGX0lEQ1NuYXBTaG90IiBzY3JvbGxpbmc9Im5vIiBmcmFtZWJvcmRlcj0iMCI%%2BPC9pZnJhbWU%%2BZAIDD2QWBAIBDxYCHgtfIUl0ZW1Db3VudAIDFghmD2QWAmYPFQULIm1hcmtldEFsdCILQ0JPRSBWb2x1bWUHNDg0NDkxMwciZ3JlZW4iASBkAgEPZBYCZg8VBQgibWFya2V0IgtDQlNYIFZvbHVtZQgyNjE3ODU5MgciZ3JlZW4iASBkAgIPZBYCZg8UKwIFBQsibWFya2V0QWx0ImRlBQciZ3JlZW4iZWQCAw9kFgJmDxUBCCJtYXJrZXQiZAIDDw8WBB8AZR8BaGRkAgQPZBYCAgEPZBYCAgEPFgIfAAV1PElGUkFNRSBzcmM9Imh0dHA6Ly9jYm9lLnphY2tzLmNvbS9DQk9FL215Q0JPRS5waHAiIGhlaWdodD0iMTgwIiB3aWR0aD0iMjkwIiBzY3JvbGxpbmc9Im5vIiBmcmFtZWJvcmRlcj0iMCI%%2BPC9pZnJhbWU%%2BZAIFD2QWCAIBD2QWAmYPZBYCZg9kFgICBA8UKwACDxYEHgtfIURhdGFCb3VuZGcfAgIFZGQWAmYPZBYKAgEPZBYCAgEPZBYCZg8VBCQvaW1hZ2VzL2xlYXJuY2VudGVyL2VkdWNhdGlvbi0wMi5wbmc9aHR0cDovL3d3dy5jYm9lLmNvbS9MZWFybkNlbnRlci9WaWV3U2VtaW5hci5hc3B4P1NlbWluYXJJZD0zOB5PcHRpb25zIEluc3RpdHV0ZSBQbHVzIC0gRWxpdGVOQWNxdWlyZSBFbGl0ZSBzdGF0dXMgaW4gb3VyIE9wdGlvbnMgSW5zdGl0dXRlIFBsdXMgcHJvZ3JhbSBpbmNsdXNpdmUgb2YgZXZlLi4uZAICD2QWAgIBD2QWAmYPFQQkL2ltYWdlcy9sZWFybmNlbnRlci9lZHVjYXRpb24tMDIucG5nPWh0dHA6Ly93d3cuY2JvZS5jb20vTGVhcm5DZW50ZXIvVmlld1NlbWluYXIuYXNweD9TZW1pbmFySWQ9MzUpT3B0aW9ucyBJbnN0aXR1dGUgUGx1cyAtIExldmVsIDEgQmVnaW5uZXJOVGhpcyAyLWRheSBjbGFzc3Jvb20gZXhwZXJpZW5jZSBwbHVzIDEwIGhvdXJzIG9mIGRpc3RhbmNlIGNvYWNoaW5nIHdpbGwgaW50Li4uZAIDD2QWAgIBD2QWAmYPFQQkL2ltYWdlcy9sZWFybmNlbnRlci9lZHVjYXRpb24tMDIucG5nPWh0dHA6Ly93d3cuY2JvZS5jb20vTGVhcm5DZW50ZXIvVmlld1NlbWluYXIuYXNweD9TZW1pbmFySWQ9MzctVGhlIE9wdGlvbnMgSW5zdGl0dXRlIFBsdXMgLSBMZXZlbCAzIEFkdmFuY2VkTlRoaXMgMS1kYXkgY2xhc3Nyb29tIGV4cGVyaWVuY2UgcGx1cyAxMCBob3VycyBvZiBkaXN0YW5jZSBjb2FjaGluZyBkaXNjdXNzZS4uLmQCBA9kFgICAQ9kFgJmDxUEJC9pbWFnZXMvbGVhcm5jZW50ZXIvZWR1Y2F0aW9uLTAyLnBuZz1odHRwOi8vd3d3LmNib2UuY29tL0xlYXJuQ2VudGVyL1ZpZXdTZW1pbmFyLmFzcHg%%2FU2VtaW5hcklkPTE4HlJlYWwgVHJhZGluZyB3aXRoIERhbiBTaGVyaWRhbk5TZW1pbmFyIGV4cGxvcmVzIHdheSB0byByZWFsaXplIGNvbnNpc3RlbnQgaW5jb21lIGZyb20gIm9mZi1mbG9vciIgb3B0aW9ucyAuLi5kAgUPZBYCAgEPZBYCZg8VBCQvaW1hZ2VzL2xlYXJuY2VudGVyL2VkdWNhdGlvbi0wMi5wbmc9aHR0cDovL3d3dy5jYm9lLmNvbS9MZWFybkNlbnRlci9WaWV3U2VtaW5hci5hc3B4P1NlbWluYXJJZD0zNi1PcHRpb25zIEluc3RpdHV0ZSBQbHVzIC0gTGV2ZWwgMiBJbnRlcm1lZGlhdGVOVGhpcyAyLWRheSBjbGFzc3Jvb20gZXhwZXJpZW5jZSBwbHVzIDEwIGhvdXJzIG9mIGRpc3RhbmNlIGNvYWNoaW5nIHdpbGwgZXhwLi4uZAIDDxYCHwAFwwc8aDM%%2BQm9va3M8L2gzPjxwPjx1bD48bGk%%2BPGEgY2xhc3M9J2Fycm93LXVwJyBocmVmPSdodHRwOi8vd3d3LmNib2UuY29tL0ZyYW1lZC9Cb29rU3RvcmVGcmFtZWQuYXNweD9jb250ZW50PWh0dHA6Ly93d3cuaW52ZXN0LXN0b3JlLmNvbS9jZ2ktYmluL2Nib2UtYmluL21vcmVpbmZvLmNnaT9pdGVtPTE3NTU0Jz5CaWcgVHJlbmRzIGluIFRyYWRpbmc8L2E%%2BPC9saT48bGk%%2BPGEgY2xhc3M9J2Fycm93LXVwJyBocmVmPSdodHRwOi8vd3d3LmNib2UuY29tL0ZyYW1lZC9Cb29rU3RvcmVGcmFtZWQuYXNweD9jb250ZW50PWh0dHA6Ly93d3cuaW52ZXN0LXN0b3JlLmNvbS9jZ2ktYmluL2Nib2UtYmluL21vcmVpbmZvLmNnaT9pdGVtPTU5MzEwMjcnPkxFQVBTIFRyYWRpbmcgU3RyYXRlZ2llczwvYT48L2xpPjwvdWw%%2BPC9wPjxoMz5TZW1pbmFyczwvaDM%%2BPHA%%2BPHVsPjxsaT48YSBjbGFzcz0nYXJyb3ctdXAnIGhyZWY9Jy9MZWFybkNlbnRlci9FZHVjYXRpb25hbFRvdXJzLmFzcHgnPlRoZSBDQk9FIEV4cGVyaWVuY2U8L2E%%2BPC9saT48bGk%%2BPGEgY2xhc3M9J2Fycm93LXVwJyBocmVmPScnPk9wdGlvbnMgSW5zdGl0dXRlIFBsdXMgLSBNSU5JIExldmVsIDEgQmVnaW5uZXI8L2E%%2BPC9saT48L3VsPjwvcD48aDM%%2BU3RyYXRlZ3kgb2YgdGhlIFdlZWsgV2ViY2FzdHM8L2gzPjxwPjx1bD48bGk%%2BPGEgY2xhc3M9J2Fycm93LXVwJyBocmVmPSdodHRwOi8vd3d3LmNib2UuY29tL1RyYWRUb29sL3dlYmNhc3QuYXNweD9jaGFubmVsPTE0MzAmbW92aWVpZD00NTQ0Myc%%2BU3RyYXRlZ3kgb2YgdGhlIFdlZWsgQ2FsZW5kYXIgU3ByZWFkPC9hPjwvbGk%%2BPGxpPjxhIGNsYXNzPSdhcnJvdy11cCcgaHJlZj0naHR0cDovL3d3dy5jYm9lLmNvbS9UcmFkVG9vbC93ZWJjYXN0LmFzcHg%%2FY2hhbm5lbD0xNDMwJm1vdmllaWQ9NDUwNTknPlN0cmF0ZWd5IG9mIHRoZSBXZWVrIFNlbGxpbmcgQSBQdXQ8L2E%%2BPC9saT48L3VsPjwvcD5kAgUPFgIfAWdkAgkPFgIfAWhkAgYPZBYCAgEPDxYCHwAF5AFQcm90ZWN0aXZlIFB1dDxicj48YnI%%2BUHJvdGVjdGl2ZSBQdXQNCg0KIA0KDQpFeGFtcGxlOiAgICAgICAgICAgICAgICAgWW91IG93biAxMDAgc2hhcmVzIG9mIFhZWiBzdG9jayBhdCAkNTEuNTAuDQoNCiANCg0KT3V0bG9vazogICAgICAgICAgICAgICAgICBZb3UgYXJlIG1vZGVyYXRlbHkgYnVsbGlzLi4uIDxBIGhyZWY9Ii9TdHJhdGVnaWVzL1dlZWtseVN0cmF0ZWd5LmFzcHgiPihtb3JlKTwvQT5kZAIHD2QWAmYPZBYCAgEPDxYCHwAFvgFXaGljaCBJbmRleCBFVEYncyBoYXZlIGVsZWN0cm9uaWNhbGx5IHRyYWRlZCBvcHRpb25zPyBGb3IgZXhhbXBsZSwgU1BZIGRvZXMgbm90IHRyYWRlIG9wdGlvbnMgZWxlY3Ryb25pY2FsbHkuIFNQWSB1c2VzICJNYXJrZXQgTWFrZXJzIi4gT24gdGhlIG90aGVyIGhhbmQsIElXTSBvcHRpb25zIHRyYWRlIGVsZWN0cm9uaWNhbGx5Li4uZGQYAgUeX19Db250cm9sc1JlcXVpcmVQb3N0QmFja0tleV9fFgIFQ2N0bDAwJGN0bDAwJEFsbENvbnRlbnQkdWNIZWFkZXIkdWNDQk9FSGVhZGVyUXVvdGVCb3gkYnRuSGVhZGVyUXVvdGUFQ2N0bDAwJGN0bDAwJEFsbENvbnRlbnQkdWNIZWFkZXIkQ0JPRUhlYWRlclNlYXJjaEJveCRidG5IZWFkZXJTZWFyY2gFaGN0bDAwJGN0bDAwJEFsbENvbnRlbnQkdWNSaWdodEJhciR1Y0NCT0VNeUNCT0UkdWNMQ0VkdVRhYnMkdWNDQk9FUGFnaW5hdGVNYW51YWwkY3RsMDAkbHZFZHVGZWF0dXJlZEV2ZW50DzwrAAoCBzwrAAUACAIFZNpjM%%2B%%2FOARDLOc0XZ11QAyz2UsJ%%2B&__EVENTVALIDATION=%%2FwEWBwLznJirAgLnn5gNAtXW%%2F%%2BYLApSZ7dMOArre%%2Ba0MArm0noIMAui9nNYPDi6n8VkUoSiv%%2BApjXze5mZkrKfI%%3D&ctl00%%24ctl00%%24AllContent%%24ucHeader%%24ucCBOEHeaderQuoteBox%%24txtHeaderQuote=Quote&ctl00%%24ctl00%%24AllContent%%24ucHeader%%24CBOEHeaderSearchBox%%24txtHeaderSearch=Search&ctl00%%24ctl00%%24AllContent%%24ContentMain%%24QuoteTableDownloadCtl1%%24txtTicker=QQQQ&ctl00%%24ctl00%%24AllContent%%24ContentMain%%24QuoteTableDownloadCtl1%%24cmdSubmit=Download},$symbol);
	$req->content($content);
	$req->header("Referer" => "http://www.cboe.com/DelayedQuote/QuoteTableDownload.aspx");
	my $retries = 10;
	while ((--$retries) > 0) {
		my $res = $ua->request($req);
		printf("%s\n",$res->code);
		if ($res->code == 302) {
			printf("%s\n",$res->header("Location"));
		}
		elsif ($res->is_success) {
			my $writethis = $res->content;
			my $outputfile = sprintf($timestr,$symbol);
			my $outputfh = new IO::File($outputfile,"w");
			printf($outputfh "%s",$writethis);
			$outputfh->close();
			$retries = 0;
		}
	}
}

sub magic_mkdir($) {
	my ($dir) = @_;
	my @separated = split(/\//,$dir);
	my $sub = "";
	my $i;

	for ($i = 0; $i < scalar(@separated); ++$i) {
		$sub = $sub . $separated[$i];
		if ($sub ne "") { mkdir($sub); }
		$sub = $sub . "/";
	}
}
