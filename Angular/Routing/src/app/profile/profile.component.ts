import { NgClass } from '@angular/common';
import { Component, Input, Output,EventEmitter } from '@angular/core';
import { ActivatedRoute } from '@angular/router';

@Component({
  selector: 'app-profile',
  imports: [NgClass],
  templateUrl: './profile.component.html',
  styleUrl: './profile.component.css'
})
export class ProfileComponent {
  userName:string|null="";
  @Input() tabList:string[]= [];
  @Output() onTabClicked = new EventEmitter<string>();

  currentTab:string = "";

  onTabChange(tabName:string){
    debugger;
    this.currentTab = tabName;
    this.onTabClicked.emit(tabName);
  }
  constructor(private route:ActivatedRoute) {}
  ngOnInit(){
    // this.userName = this.route.snapshot.paramMap.get('name');
    // console.log(this.userName);

    // this.route.queryParams.subscribe(params => {
    //   this.userName = params['name'];
    // });

    this.route.data.subscribe(data=>
    {
      this.userName = data['name'];
    });

  }
}
