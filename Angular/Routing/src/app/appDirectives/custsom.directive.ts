import { Directive, ElementRef, OnInit } from '@angular/core';

@Directive({
  selector: '[appCustom]'
})
export class CustsomDirective implements OnInit {

  constructor(private el: ElementRef) { }
  ngOnInit(): void {
    this.el.nativeElement.style.backgroundColor = 'lightblue';
    this.el.nativeElement.style.width = '200px';
    this.el.nativeElement.style.height = '130px';
    this.el.nativeElement.style.padding = '10px';
    

    // this.el.nativeElement.classList.add('custom-directive'); css class can be added
  }

}
