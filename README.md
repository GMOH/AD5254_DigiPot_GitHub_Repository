AD5254_DigiPot_GitHub_Repository
================================

    AD525X Digital potentiometer demo program.
    This code Starts by reading all current Pots Values and the EEMEM stored values.
    The EEMEM stored values are the values that the pots start at power up.
    Pot Values are from 0 - 255 for 0 to full scale resistance.
    
    After it shows the values in the serial monitor, it requests a value for RDAC0
    Sets the wiper for RDAC0 to the corresponding resistnace and stores the value to EEMEM0
    
    More documentation can be found at http://familia-herrera.com/wordpress/archives/576
    Copyright (C) 2014  Guillermo Herrera

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
   
Notes:
Currently the files are stanalone files fully functional.  The Goal is to make a library that can be dropped in the arduino library folder with an example on how to use the code.  (Working on it)

Any help from others is welcome

ToDo:
1. Add open hardware license to EAGLE files
2. Create *.h file for library
3. Update Website with more details and videos

Change Log:
4/8/14  First commit, arduino code files, EAGLE board files.
4/9/14  Added license file, description to individual files 
