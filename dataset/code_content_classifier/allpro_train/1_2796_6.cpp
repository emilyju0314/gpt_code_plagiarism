#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:200000000")
const double EPS = 1E-9;
const int INF = 1000000000;
const long long INF64 = (long long)1E18;
const double PI = 3.1415926535897932384626433832795;
string tr[3][50] = {{"BRITISH, FRENCH MINISTERS DISCUSS PUBLIC SPENDING",
                     "FORMER HERSTATT DEALER CAN BE SUED, COURT RULES",
                     "U.K. MONEY MARKET DEFICIT FORECAST AT 700 MLN STG",
                     "BANK OF SPAIN SUSPENDS ASSISTANCE",
                     "U.K. MONEY MARKET GIVEN 265 MLN STG ASSISTANCE",
                     "BANK OF FRANCE AGAIN BUYING DOLLARS, SOURCES SAY",
                     "BUNDESBANK BOUGHT DOLLARS AGAINST YEN, DEALERS SAY",
                     "U.K. MONEY MARKET GIVEN FURTHER 663 MLN STG HELP",
                     "AUSTRIA DOES NOT INTERVENE TO SUPPORT DOLLAR",
                     "TAIWAN TO STUDY SUSPENDING FOREX CONTROLS",
                     "OFFICIAL WANTS ARAB FUND TO HELP LEBANESE POUND",
                     "CHINA POSTPONES PLAN TO SCRAP PARALLEL CURRENCY",
                     "ARAB BANKER SAYS TOO SOON FOR SINGLE CURRENCY",
                     "ARAB FOREX ASSOCIATION ELECTS NEW CHAIRMAN",
                     "JAPAN CAREFULLY CONSIDERING MONEY POLICY -- SUMITA",
                     "BAHRAIN INTRODUCES NEW MONEY MARKET REGIME",
                     "BANK OF ENGLAND FORECASTS SURPLUS IN MONEY MARKET",
                     "PHILADELPHIA EXCHANGE TO EXTEND HOURS FOR ASIA",
                     "JAPAN CONDUCTS CURRENCY SURVEY OF BIG INVESTORS",
                     "BANK OF ENGLAND DOES NOT OPERATE IN MONEY MARKET",
                     "ASIAN DOLLAR MARKET ASSETS FALL IN JANUARY",
                     "PHILADELPHIA EXCHANGE TO EXTEND HOURS FOR ASIA",
                     "JAPAN CAREFULLY CONSIDERING MONEY POLICY - SUMITA",
                     "U.K. MONEY MARKET GIVEN 129 MLN STG ASSISTANCE",
                     "JAPAN CONDUCTS CURRENCY SURVEY OF BIG INVESTORS",
                     "JAPANESE SEEN LIGHTENING U.S. BOND HOLDINGS",
                     "FED ADDS RESERVES VIA CUSTOMER REPURCHASES",
                     "FORMER TREASURY OFFICIAL URGES CURRENCY REFORMS",
                     "FED WILL BUY BILLS FOR CUSTOMER AFTER AUCTION",
                     "TREASURY BALANCES AT FED FELL ON MARCH 27",
                     "U.S. CREDIT MARKETS END UNDER EXTREME PRESSURE",
                     "U.K. MONEY MARKET OFFERED EARLY ASSISTANCE",
                     "UK MONEY MARKET GIVEN FURTHER 570 MLN STG HELP",
                     "CALL MONEY PRESSURE FROM LARGE GERMAN BANKS",
                     "U.K. MONEY MARKET SHORTAGE FORECAST REVISED UP",
                     "U.K. MONEY MARKET GIVEN 215 MLN STG LATE HELP",
                     "U.S. TREASURY'S BAKER SEES RATE STABILITY",
                     "TREASURY'S BAKER SAYS COOPERATION WORKING",
                     "TREASURY'S BAKER SAYS U.S. BACKS STABILITY",
                     "BANGEMANN CALLS FOR CURRENCY CALM",
                     "TREASURY'S BAKER PURSUING S. ASIAN REVALUATIONS",
                     "TREASURY'S BAKER PURSUING S. ASIAN REVALUATIONS",
                     "CURRENCY FUTURES CLIMB LIKELY TO BE CHECKED",
                     "U.S. FED EXPLORES COMMODITY BASKET INDEX",
                     "U.K. MONEY MARKET OFFERED EARLY ASSISTANCE",
                     "U.K. MONEY MARKET GIVEN 689 MLN STG EARLY HELP",
                     "U.K. MONEY MARKET SHORTAGE FORECAST REVISED UP",
                     "U.K. MONEY MARKET DEFICIT REVISED DOWNWARDS",
                     "FED BUYS ONE BILLION DLRS OF BILLS FOR CUSTOMER",
                     "FED BUYS ONE BILLION DLRS OF BILLS FOR CUSTOMER"},
                    {"N.Z. TRADING BANK DEPOSIT GROWTH RISES SLIGHTLY",
                     "NEW YORK BUSINESS LOANS FALL 222 MLN DLRS",
                     "U.S. M-1 MONEY SUPPLY RISES 1.2 BILLION DLR",
                     "CANADIAN MONEY SUPPLY FALLS IN WEEK",
                     "DUTCH MONEY SUPPLY HARDLY CHANGED IN DECEMBER",
                     "U.K. CONFIRMS FEBRUARY STERLING M3 RISE",
                     "SINGAPORE M-1 MONEY SUPPLY 2.7 PCT UP IN JANUARY",
                     "SINGAPORE BANK CREDIT RISES IN JANUARY",
                     "H.K. M3 MONEY SUPPLY RISES 1.4 PCT IN FEBRUARY",
                     "U.S. BANK DISCOUNT BORROWINGS 310 MLN DLRS",
                     "U.S. M-1 MONEY SUPPLY ROSE 2.1 BILLION DLRS",
                     "AUSTRALIAN BROAD MONEY GROWTH 10.3 PCT IN FEBRUARY",
                     "TAIWAN ISSUES MORE CERTIFICATES OF DEPOSIT",
                     "SOUTH KOREAN MONEY SUPPLY FALLS IN MARCH",
                     "BELGIAN MONEY SUPPLY RISES IN FOURTH QUARTER 1986",
                     "CANADIAN MONEY SUPPLY FALLS IN WEEK",
                     "TREASURY BALANCES AT FED ROSE ON FEB 27",
                     "FEBRUARY FOMC VOTES UNCHANGED MONETARY POLICY",
                     "U.S. BUSINESS LOANS FELL 822 MLN DLRS",
                     "GERMAN CAPITAL ACCOUNT IN DEFICIT IN FEBRUARY",
                     "TREASURY BALANCES AT FED ROSE ON APRIL 6",
                     "TAIWAN ISSUES MORE CDS TO CURB MONEY SUPPLY GROWTH",
                     "SOUTH KOREAN MONEY SUPPLY RISES IN FEBRUARY",
                     "SPAIN RAISES BANKS' RESERVE REQUIREMENT",
                     "N.Z. MONEY SUPPLY RISES 3.6 PCT IN DECEMBER",
                     "FED DATA SUGGEST STABLE U.S. MONETARY POLICY",
                     "N.Z. CENTRAL BANK SEES SLOWER MONEY, CREDIT GROWTH",
                     "U.S. M-1 MONEY SUPPLY RISES 1.9 BILLION DLRS",
                     "U.S. MONEY GROWTH SLOWS SHARPLY, ECONOMISTS SAY",
                     "CANADIAN MONEY SUPPLY RISES IN WEEK",
                     "TREASURY BALANCES AT FED FELL ON MARCH 5",
                     "U.S. BUSINESS LOANS FALL 618 MLN DLRS",
                     "SINGAPORE M-1 MONEY SUPPLY UP 3.7 PCT IN DECEMBER",
                     "FRENCH JANUARY M-3 MONEY SUPPLY RISES ONE PCT",
                     "U.K. CONFIRMS JANUARY STERLING M3 RISE",
                     "TREASURY BALANCES AT FED ROSE ON MARCH 6",
                     "SPAIN'S MONEY SUPPLY GROWTH DOUBLES IN FEBRUARY",
                     "TREASURY BALANCES AT FED FELL ON MARCH 10",
                     "NEW YORK BUSINESS LOANS FALL 718 MLN DLRS",
                     "U.S. M-1 MONEY SUPPLY FALLS 600 MLN DLRS",
                     "JAPAN PERSONAL SAVINGS SOAR IN 1986",
                     "CANADIAN MONEY SUPPLY RISES IN WEEK",
                     "U.S. BUSINESS LOANS RISE 377 MLN DLRS",
                     "BANGLADESH MONEY SUPPLY RISES IN DECEMBER",
                     "GERMAN FEBRUARY CENTRAL BANK MONEY GROWTH STEADY",
                     "THAI M-1 MONEY SUPPLY RISES IN JANUARY",
                     "JAPAN FEBRUARY MONEY SUPPLY RISES 8.8 PCT",
                     "ASSETS OF U.S. MONEY FUNDS ROSE IN WEEK",
                     "ITALY M-2 UP 2.8 PCT IN 3 MONTHS TO END JANUARY",
                     "PHILIPPINES' LIQUIDITY RISES, LOAN DEMAND FALLS"},
                    {"WHITE HOUSE UNIT DECIDES ON SEMICONDUCTORS",
                     "CHINA CALLS FOR BETTER TRADE DEAL WITH U.S.",
                     "GATT WARNS U.S. ON FEDERAL BUDGET, PROTECTIONISM",
                     "WHITE HOUSE PANEL SAID URGING JAPAN RETALIATION",
                     "NAKASONE TO VISIT WASHINGTON IN LATE APRIL",
                     "WORLD BANK CHIEF URGES MORE JAPANESE INVESTMENT",
                     "NAKASONE TO VISIT WASHINGTON IN LATE APRIL",
                     "NAKASONE HARD-PRESSED TO SOOTHE U.S ANGER ON TRADE",
                     "INDIA STEPS UP COUNTERTRADE DEALS TO CUT TRADE GAP",
                     "UK MAY REVOKE JAPANESE FINANCIAL LICENSES",
                     "REAGAN READY TO IMPOSE TRADE CURBS AGAINST JAPAN",
                     "JAPAN'S CHIP MAKERS ANGERED BY U.S. SANCTION PLANS",
                     "NAKASONE SOUNDS CONCILIATORY NOTE IN CHIP DISPUTE",
                     "ISLAMIC BANKS ESTABLISH 50 MLN DLR TRADE PORTFOLIO",
                     "TOKYO BIDS TO STOP CHIP ROW TURNING INTO TRADE WAR",
                     "BALDRIGE PREDICTS END OF U.S.-JAPAN TRADE DISPUTE",
                     "JAPAN HAS LITTLE NEW TO OFFER IN MICROCHIP DISPUTE",
                     "NAKASONE SOUNDS CONCILIATORY NOTE IN CHIP DISPUTE",
                     "TOKYO BIDS TO STOP CHIP ROW BECOMING TRADE WAR",
                     "BALDRIGE PREDICTS END OF U.S.-JAPAN TRADE DISPUTE",
                     "YUGOSLAV TRADE FALLS SHARPLY  STATISTICS SHOW",
                     "ECONOMIC SPOTLIGHT - U.S. CONGRESS RAPS JAPAN",
                     "U.S. TRADE OFFICIAL SAYS JAPAN ACTION FOOLISH",
                     "EUROPEAN COMMUNITY TO SET UP OFFICE IN PEKING",
                     "TRADE FRICTION THREATENS TO TOPPLE NAKASONE",
                     " EUROPE ON SIDELINES IN U.S-JAPAN MICROCHIP ROW",
                     "THATCHER SAYS TRADE TARGETS SET WITH MOSCOW",
                     "JAPAN TO CUT MICROCHIP OUTPUT, BOOST IMPORTS",
                     "JAPAN WILL ASK COMPANIES TO BOOST IMPORTS",
                     "U.S./JAPAN TRADE WAR NOT IN UK'S INTEREST - LAWSON",
                     "EC APPROVES MEDITERRANEAN FINANCIAL PACKAGES",
                     "SOVIET UNION SEEN WATCHING CHINA GATT APPLICATION",
                     "U.S. SENATE LEADERS SEE NO TRADE WAR BREWING",
                     "U.S. STOCK MARKET OVERREACTS TO TARIFFS - YEUTTER",
                     "ENVOY ADVISES NAKASONE TO PREPARE FOR U.S. VISIT",
                     "TREASURY'S BAKER SEES SMALLER TRADE DEFICIT",
                     "TREASURY'S BAKER NOT CONCERNED BY BOND DECLINES",
                     "U.S.-JAPAN NOT IN TRADE WAR, YEUTTER SAYS",
                     "CHIRAC, REAGAN DISCUSS ARMS CONTROL, TRADE",
                     "TRADE WAR FEARS MAY PROMPT STOCK MARKETS' DOWNTURN",
                     "WHITE HOUSE DISCOUNTS THREAT OF TRADE WAR",
                     "BALDRIGE SAYS U.S. TO IMPOSE JAPANESE SANCTIONS",
                     "SENIOR U.S. OFFICIAL TO VISIT JAPAN AS TRADE ROW GROWS",
                     "BROADER U.S. EEP SOUGHT BY REPUBLICAN LAWMAKERS",
                     "U.S. OFFICIAL TO VISIT JAPAN AS TRADE ROW GROWS",
                     "U.S. OFFICIAL SEES EVIDENCE OF EXPORT GROWTH",
                     "TAIWAN'S SECOND QUARTER IMPORTS SEEN RISING",
                     "BELGIAN SAYS EC WOULD REACT TO TEXTILE BILL",
                     "ROSTENKOWSKI OPPOSES PROTECTIONIST TRADE BILL",
                     "U.K. EXPORTS BODY GETS NEW EXECUTIVE DIRECTOR"}};
char buf[1100000];
string trim(string s) {
  string res;
  for (int i = 0; i < (int)(s.size()); i++)
    if (isalpha(s[i]) || isdigit(s[i])) res += s[i];
  return res;
}
bool match(string s1, string s2) { return trim(s1) == trim(s2); }
int main() {
  gets(buf);
  string text;
  while (gets(buf)) {
    text += buf;
    break;
  }
  for (int i = 0; i < (int)(3); i++)
    for (int j = 0; j < (int)(i); j++)
      for (int a = 0; a < (int)(50); a++)
        for (int b = 0; b < (int)(50); b++)
          if (match(tr[i][a], tr[j][b])) throw;
  for (int i = 0; i < (int)(3); i++)
    for (int j = 0; j < (int)(50); j++)
      if (match(text, tr[i][j])) {
        printf("%d\n", i + 1);
        return 0;
      }
  return 0;
}
