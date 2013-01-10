# PCRE JIT benchmark

Sample data and regular expressions are taken from [Benchmark of Regex Libraries](http://lh3lh3.users.sourceforge.net/reb.shtml).
The benchmark source code was also taken from there and modified to use pcre native APIs and the PCRE_STUDY_JIT_COMPILE option. See ["man pcrejit"](http://www.manpagez.com/man/3/pcrejit/)

Tested environment: CentOS 6.3 on VirtualBox 4.2.6, MacBook Pro 2012, Core i7 2.6GHz, 16GB 1600MHz DDR3 RAM, Apple SSD

<table style="border-collapse: collapse; border: solid; text-align: right;">
  <tr>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;"></td>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">URI</td>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">Email</td>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">Date</td>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">URI | Email</td>
  </tr>
  <tr style="border-style: solid; border-width:2px 0 0 0; padding: 4px;">
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">PCRE 7.8 no jit</td>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">0.365s</td>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">0.218s</td>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">0.203s</td>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">7.477s</td>
  </tr>
  <tr style="border-style: solid; border-width:1px 0 0 0; padding: 4px;">
    <td style="border-style: solid; border-width:0 1px; padding: 4px;" rowspan="3">PCRE 8.32 no jit</td>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">0.348s</td>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">0.211s</td>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">0.197s</td>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">6.885s</td>
  </tr>
  <tr>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">-0.017s</td>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">-0.007s</td>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">-0.006s</td>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">-0.592s</td>
  </tr>
  <tr>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">-4.7%</td>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">-3.2%</td>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">-3.0%</td>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">-7.9%</td>
  </tr>
  <tr style="border-style: solid; border-width:1px 0 0 0; padding: 4px;">
    <td style="border-style: solid; border-width:0 1px; padding: 4px;" rowspan="3">PCRE 8.32 jit</td>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">0.200s</td>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">0.166s</td>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">0.175s</td>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">1.184s</td>
  </tr>
  <tr>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">-0.148s</td>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">-0.045s</td>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">-0.022s</td>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">-5.701s</td>
  </tr>
  <tr>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">-42.5%</td>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">-21.3%</td>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">-11.2%</td>
    <td style="border-style: solid; border-width:0 1px; padding: 4px;">-82.8%</td>
  </tr>
</table>